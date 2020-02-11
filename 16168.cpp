#include<bits/stdc++.h>
using namespace std;
int d[3010];
struct UF{
	int p[3010];
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
int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;
	cin>>n>>m;
	UF uf;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		d[a]++;
		d[b]++;
		uf.mer(a,b);
	}
	if(uf.p[uf.fnd(1)]!=-n){
		cout<<"NO";
		return 0;
	}
	int c=0;
	for(int i=1;i<=n;i++){
		c+=d[i]%2;
	}
	if(c==0||c==2)cout<<"YES";
	else cout<<"NO";
}
