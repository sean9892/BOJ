#include<bits/stdc++.h>
using namespace std;
using edge=tuple<int,int,int>;
const int nmax=100010;

#define fastio do{ios::sync_with_stdio(0);cin.tie(0);}while(0)

class UnionFind{
public:
	int p[nmax];
	UnionFind(){
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
int qv[nmax][2];
edge e[nmax];
int lo[nmax]={0},hi[nmax];
int r[nmax][2];

int main(void){
	fastio;
	
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]=edge(w,u-1,v-1);
	}
	sort(e,e+m);
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>qv[i][0]>>qv[i][1];
		--qv[i][0];--qv[i][1];
	}
	
	fill(hi,hi+nmax,m+1);
	
	while(1){
		int flag=1;
		vector<int> x[nmax];
		for(int i=0;i<q;i++){
			if(lo[i]+1<hi[i]){
				flag=0;
				x[(lo[i]+hi[i])>>1].push_back(i);
			}
		}
		if(flag)break;
		
		UnionFind uf;
		for(int i=0;i<m;i++){
			int u,v,w;
			tie(w,u,v)=e[i];
			uf.mer(u,v);
			for(int j:x[i+1]){
				int a=uf.fnd(qv[j][0]),b=uf.fnd(qv[j][1]);
				if(a==b){
					hi[j]=i+1;
					r[j][0]=w;
					r[j][1]=-uf.p[uf.fnd(a)];
				}
				else lo[j]=i+1;
			}
		}
	}
	
	for(int i=0;i<q;i++){
		if(lo[i]==m)cout<<"-1\n";
		else cout<<r[i][0]<<" "<<r[i][1]<<"\n";
	}
}
