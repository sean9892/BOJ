#include<bits/stdc++.h>
using namespace std;
using edge = tuple<int,int,int>;

const int nmax=200010;
const int emax=500010;

struct UF{
	int p[nmax];
	UF(){
		memset(p,-1,sizeof(p));
	}
	int fnd(int u){
		return p[u]<0?u:(p[u]=fnd(p[u]));
	}
	int mer(int u,int v){
		u=fnd(u);v=fnd(v);
		if(u==v)return 0;
		p[u]+=p[v];
		p[v]=u;
		return 1;
	}
};

int n,m,q;
edge e[emax];
int qv[nmax][2];
int lo[nmax],hi[nmax];
int r[nmax];

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>q;
	fill(hi,hi+nmax,m+1);
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		e[i]=edge(c,a-1,b-1);
	}
	sort(e,e+m,greater<edge>());
	for(int i=0;i<q;i++){
		cin>>qv[i][0]>>qv[i][1];
		--qv[i][0];--qv[i][1];
	}
	
	while(1){
		int flag=1;
		vector<int> x[emax];
		for(int i=0;i<q;i++){
			if(lo[i]+1<hi[i]){
				flag=0;
				x[lo[i]+hi[i]>>1].push_back(i);
			}
		}
		if(flag)break;
		UF uf;
		for(int i=0;i<m;i++){
			int u,v,w;
			tie(w,u,v)=e[i];
			uf.mer(u,v); 
			for(int j:x[i+1]){
				int a=uf.fnd(qv[j][0]),b=uf.fnd(qv[j][1]);
				if(a==b){
					hi[j]=i+1;
					r[j]=w;
				}
				else lo[j]=i+1;
			}
		}
	}
	
	for(int i=0;i<q;i++){
		cout<<r[i]<<"\n";
	}
}
