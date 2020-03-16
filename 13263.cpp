#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second

using ll=long long;
using line=pair<ll,ll>;

const ll inf=2e18;

ll f(line l,ll x){
	return l.fi*x+l.se;
}

struct node{
	int le,ri;
	ll xl,xr;
	line l;
	node(int a=0,int b=0,ll c=0,ll d=0,line e=line(0,0)):le(a),ri(b),xl(c),xr(d),l(e){}
};

struct LiChao{
	vector<node> v;
	
	void init(ll xmin,ll xmax){
		v.emplace_back(-1,-1,xmin,xmax,line(0,-inf));
	}
	
	void insert(int n,line nl){
		ll xl=v[n].xl,xr=v[n].xr;
		ll xm=xl+xr>>1;
		
		line llo=v[n].l,lhi=nl;
		if(f(llo,xl)>f(lhi,xl))swap(llo,lhi);
		
		if(f(llo,xr)<=f(lhi,xr)){
			v[n].l=lhi;
			return;
		}
		else if(f(llo,xm)<f(lhi,xm)){
			v[n].l=lhi;
			if(v[n].ri==-1){
				v[n].ri=v.size();
				v.emplace_back(-1,-1,xm+1,xr,line(0,-inf));
			}
			insert(v[n].ri,llo);
		}
		else{
			v[n].l=llo;
			if(v[n].le==-1){
				v[n].le=v.size();
				v.emplace_back(-1,-1,xl,xm,line(0,-inf));
			}
			insert(v[n].le,lhi);
		}
	}
	
	ll get(int n,ll x){
		if(n==-1)return -inf;
		ll xl=v[n].xl,xr=v[n].xr;
		ll xm=xl+xr>>1;
		if(x<=xm)return max(f(v[n].l,x),get(v[n].le,x));
		else return max(f(v[n].l,x),get(v[n].ri,x));
	}
};

ll a[100010];
ll b[100010];
ll dp[100010];
LiChao lct;

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	lct.init(1,1e9);
	dp[1]=0;
	lct.insert(0,line(-b[1],0));
	for(int i=2;i<=n;i++){
		dp[i]=lct.get(0,a[i]);
		lct.insert(0,line(-b[i],dp[i]));
	}
	cout<<-dp[n];
}
