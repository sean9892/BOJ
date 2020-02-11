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

/*=======================================*/

int fin;

struct mach{
	ll d,p,r,g;
	bool operator<(mach x){
		return d<x.d;
	}
};

int tcnum;
void TC(){
	tcnum++;
	
	ll N,C,D;
	
	cin>>N>>C>>D;
	if(!N&&!C&&!D){
		fin=1;
		return;
	}
	
	vector<mach> v;
	
	for(ll i=0;i<N;i++){
		ll d,p,r,g;
		cin>>d>>p>>r>>g;
		v.push_back({d,p,r,g});
	}
	sort(v.begin(),v.end());
	
	LiChao lct;
	lct.init(0,2e9);
	lct.insert(0,line(0,C));
	
	for(ll i=0;i<N;i++){
		ll d,p,r,g;
		d=v[i].d;p=v[i].p;r=v[i].r;g=v[i].g;
		ll k=lct.get(0,d-1);
		if(k>=p){
			lct.insert(0,line(g,-d*g-p+r+k));
		}
	}
	cout<<"Case "<<tcnum<<": "<<lct.get(0,D)<<"\n";
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	while(!fin){
		TC();
	}
}
