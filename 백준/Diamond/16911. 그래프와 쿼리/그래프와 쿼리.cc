//#define DEBUG

#ifdef DEBUG
#define TEST if(1)
#else
#define TEST if(0)
#endif

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using Edge=pair<pii,pii>;
#define fi first
#define se second

struct UF{
	int p[100010];
	stack<int> rb;//For RollBack
	UF(){
		memset(p,-1,sizeof(p));
	}
	int fnd(int u){
		if(p[u]<0)return u;
		return fnd(p[u]);
	}
	int mer(int u,int v){
		u=fnd(u);v=fnd(v);
		if(u==v){
			return 0;
		}
		if(-p[u]<-p[v])swap(u,v);
		rb.push(p[v]);
		if(p[u]==p[v]){
			p[v]=u;
			p[u]--;
			rb.push(1);
		}
		else{
			p[v]=u;
			rb.push(0);
		}
		rb.push(v);rb.push(u);
		return 1;
	}
	void rollback(){
		if(rb.empty())return;
		int u=rb.top();rb.pop();
		int v=rb.top();rb.pop();
		int c=rb.top();rb.pop();
		int d=rb.top();rb.pop();
		p[v]=d;
		p[u]+=c;
	}
};

set<pii> seg[100010<<2];

void upd(int idx,int l,int r,int s,int e,int a,int b){
	if(l>e||r<s)return;
	if(s<=l&&r<=e){
		seg[idx].insert(pii(a,b));
		return;
	}
	int m=l+r>>1,le=idx<<1,ri=le|1;
	upd(le,l,m,s,e,a,b);
	upd(ri,m+1,r,s,e,a,b);
}

struct Query{
	int type,a,b;
};

UF uf;
int N,M,Q=0;
Query qu[100010];
map<pii,int> qi;
int LiS[100010];//LifeTime Start
int LiE[100010];//LifeTime End
vector<Edge> ev;
vector<pii> qv;
int res[100010];

void solve(int idx,int l,int r){
	TEST{
		cout<<"# "<<idx<<" "<<l<<" "<<r<<"\n";
	}
	int cnt=0;
	for(auto k:seg[idx]){
		int x=uf.mer(k.fi,k.se);
		TEST{
			cout<<"[] "<<k.fi<<" "<<k.se<<" "<<x<<"\n";
		}
		cnt+=x;
	}
	TEST{
		cout<<"    |ST ";
		for(int i=1;i<=N;i++){
			cout<<uf.p[i]<<" ";
		}
		cout<<"\n";
	}
	
	if(l==r){
		res[l]=(uf.fnd(qv[l].fi)==uf.fnd(qv[l].se));
		TEST{
			cout<<"$ "<<l<<" "<<qv[l].fi<<" "<<qv[l].se<<" "<<res[l]<<" "<<cnt<<"\n";
		}
		while(cnt--){
			uf.rollback();
		}
		TEST{
			cout<<"    |    |E1 ";
			for(int i=1;i<=N;i++){
				cout<<uf.p[i]<<" ";
			}
			cout<<"\n";
		}
		return;
	}
	
	int m=l+r>>1,le=idx<<1,ri=le|1;
	solve(le,l,m);
	solve(ri,m+1,r);
	while(cnt--){
		uf.rollback();
	}
	TEST{
		cout<<"@ "<<idx<<" "<<l<<" "<<r<<"\n";
		cout<<"    |    |E2 ";
		for(int i=1;i<=N;i++){
			cout<<uf.p[i]<<" ";
		}
		cout<<"\n";
	}
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>N>>M;
	memset(LiS,-1,sizeof(LiS));
	memset(LiE,-1,sizeof(LiE));
	qv.emplace_back(-1,-1);
	for(int i=0;i<M;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(b>c)swap(b,c);
		qu[i]={a,b,c};
		if(a==1){
			qi[pii(b,c)]=i;
			LiS[i]=Q;
		}
		if(a==2){
			int k=qi[pii(b,c)];
			LiE[k]=Q;
			if(LiS[k]!=LiE[k]){
				ev.emplace_back(pii(LiS[k]+1,LiE[k]),pii(b,c));
			}
			LiS[k]=-1;
			LiE[k]=-1;
		}
		if(a==3){
			Q++;
			qv.emplace_back(b,c);
		}
	}
	for(int i=0;i<M;i++){
		if(LiS[i]!=-1&&LiE[i]==-1){
			LiE[i]=Q;
			if(LiS[i]!=LiE[i]){
				ev.emplace_back(pii(LiS[i]+1,LiE[i]),pii(qu[i].a,qu[i].b));
			}
		}
	}
	for(int i=0;i<ev.size();i++){
		upd(1,1,Q,ev[i].fi.fi,ev[i].fi.se,ev[i].se.fi,ev[i].se.se);
	}
	solve(1,1,Q);
	for(int i=1;i<=Q;i++){
		cout<<res[i]<<"\n";
	}
}