#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

using dot=pair<int,int>;
using line=pair<dot,dot>;

//CCW
int ccw(dot a,dot b,dot c){
	int r=(a.fi*b.se+b.fi*c.se+c.fi*a.se)-(a.se*b.fi+b.se*c.fi+c.se*a.fi);
	if(r>0)return 1;
	if(r<0)return -1;
	return 0;
}

//Line Cross
bool lineX(line l1,line l2){
	int a=ccw(l1.fi,l1.se,l2.fi),b=ccw(l1.fi,l1.se,l2.se),
	    c=ccw(l2.fi,l2.se,l1.fi),d=ccw(l2.fi,l2.se,l1.se);
	if(a*b==0&&c*d==0){
		if(a>b)swap(a,b);
		if(c>d)swap(c,d);
		return c<=b&&a<=d;
	}
	return a*b<=0&&c*d<=0;
}

int p[3010];

int find(int u){
	if(p[u]<0)return u;
	return p[u]=find(p[u]);
}

int merge(int u,int v){
	u=find(u);v=find(v);
	if(u==v)return 0;
	p[v]+=p[u];
	p[u]=v;
	return 1;
}

int32_t main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	memset(p,-1,sizeof(p));
	int n;
	cin>>n;
	vector<line> v;
	int cnt=n;
	int mv=0;
	for(int i=0;i<n;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		v.push_back(line(dot(a,b),dot(c,d)));
		for(int j=0;j<i;j++)if(lineX(v[j],v[i])){
			cnt-=merge(i,j);
		}
	}
	for(int i=0;i<n;i++)mv=max(mv,-p[find(i)]);
	cout<<cnt<<"\n"<<mv;
}
