#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using dot=pair<ll,ll>;

#define fi first
#define se second

dot operator-(dot a,dot b){
	return {a.fi-b.fi,a.se-b.se};
}

struct node{
	int axis;
	dot p;
	ll sx,ex;
	ll sy,ey;
	int le,ri;
};

ll sq(ll a){
	return a*a;
}

ll eDist(dot a,dot b){
	dot c=a-b;
	return sq(c.fi)+sq(c.se);
}

struct cmp{
	int k;
	cmp(int x):k(x){
	}
	bool operator()(dot a,dot b){
		if((k?a.se:a.fi)^(k?b.se:b.fi))return (k?a.se:a.fi)<(k?b.se:b.fi);
		return (k?a.fi:a.se)<(k?b.fi:b.se);
	}
};

struct KDTREE{
	node tree[300010];
	dot pt[100010];
	void mktree(int idx,int l,int r){
		ll &lx=tree[idx].sx,&hx=tree[idx].ex,&ly=tree[idx].sy,&hy=tree[idx].ey;
		lx=ly=2e9;hx=hy=-2e9;
		for(int i=l;i<=r;i++){
			lx=min(lx,pt[i].fi);
			hx=max(hx,pt[i].fi);
			ly=min(ly,pt[i].se);
			hy=max(hy,pt[i].se);
		}
		if(idx==1)tree[idx].axis=0;
		else tree[idx].axis=!tree[idx>>1].axis;
		sort(pt+l,pt+r+1,cmp(tree[idx].axis));
		int m=l+r>>1;
		tree[idx].p=pt[m];
		tree[idx].le=tree[idx].ri=-1;
		if(l<m){
			tree[idx].le=idx<<1;
			mktree(idx<<1,l,m-1);
		}
		if(m<r){
			tree[idx].ri=(idx<<1)+1;
			mktree((idx<<1)+1,m+1,r);
		}
	}
	ll mdst=5e18;
	void nns(int idx,dot p){
		const node& nd=tree[idx];
		if(nd.p!=p)mdst=min(mdst,eDist(nd.p,p));
		if(tree[idx].axis){
			if(!cmp(1)(nd.p,p)){
				if(nd.le!=-1)nns(nd.le,p);
				if(nd.ri!=-1&&sq(tree[nd.ri].sy-p.se)<mdst)nns(nd.ri,p);
			}
			else{
				if(nd.ri!=-1)nns(nd.ri,p);
				if(nd.le!=-1&&sq(tree[nd.le].ey-p.se)<mdst)nns(nd.le,p);
			}
		}
		else{
			if(!cmp(0)(nd.p,p)){
				if(nd.le!=-1)nns(nd.le,p);
				if(nd.ri!=-1&&sq(tree[nd.ri].sx-p.fi)<mdst)nns(nd.ri,p);
			}
			else{
				if(nd.ri!=-1)nns(nd.ri,p);
				if(nd.le!=-1&&sq(tree[nd.le].ex-p.fi)<mdst)nns(nd.le,p);
			}
		}
	}
};

set<dot> s;
set<dot> doub;
KDTREE kdt;
dot v[100010];

void TC(){
	s.clear();
	doub.clear();
	int n;
	cin>>n;
	int c=0;
	for(int i=0;i<n;i++){
		ll x,y;
		cin>>x>>y;
		v[i]=dot(x,y);
		if(s.find(v[i])!=s.end())doub.insert(v[i]);
		else kdt.pt[c++]=v[i];
		s.insert(v[i]);
	}
	kdt.mktree(1,0,c-1);
	for(int i=0;i<n;i++){
		if(doub.find(v[i])==doub.end()){
			kdt.mdst=5e18;
			kdt.nns(1,v[i]);
			cout<<kdt.mdst<<"\n";
		}
		else{
			cout<<"0\n";
		}
	}
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int tc;
	cin>>tc;
	cout<<tc<<"\n";
	while(tc--)TC();
}
