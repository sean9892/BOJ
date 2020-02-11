#include<bits/stdc++.h>
using namespace std;

const int nmax=200010;

struct node{
	int lo,hi;
} seg[nmax<<2];

node f(node a,node b){
	return {min(a.lo,b.lo),max(a.hi,b.hi)};
}

void upd(int idx,int l,int r,int p,int v){
	if(l>p||r<p)return;
	if(l!=r){
		int m=l+r>>1,le=idx<<1,ri=le|1;
		upd(le,l,m,p,v);upd(ri,m+1,r,p,v);
		seg[idx]=f(seg[le],seg[ri]);
		return;
	}
	seg[idx].lo=seg[idx].hi=v;
}

node chk(int idx,int l,int r,int s,int e){
	if(l>e||r<s)return {987654321,-987654321};
	if(s<=l&&r<=e)return seg[idx];
	int m=l+r>>1,le=idx<<1,ri=le|1;
	return f(chk(le,l,m,s,e),chk(ri,m+1,r,s,e));
}

int query(int idx,int l,int r,int p){
	if(l>p||r<p)return 0;
	if(l!=r){
		int m=l+r>>1,le=idx<<1,ri=le|1;
		return query(le,l,m,p)|query(ri,m+1,r,p);
	}
	return seg[idx].lo;
}

int p[200010];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		upd(1,1,n,x,i);
		p[i]=x;
	}
	for(int i=0;i<m;i++){
		int t,x,y;
		cin>>t>>x>>y;
		if(t==1){
			int a=query(1,1,n,p[x]),b=query(1,1,n,p[y]);
			upd(1,1,n,p[x],b);upd(1,1,n,p[y],a);
			swap(p[x],p[y]);
		}
		else{
			node r=chk(1,1,n,x,y);
			cout<<(r.lo==x&&r.hi==y?"YES\n":"NO\n");
		}
	}
}
