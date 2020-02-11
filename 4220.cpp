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

struct mach{
	ll d,p,r,g;
	bool operator<(mach x){
		return d<x.d;
	}
};

int tccnt;
void TC(){
	tccnt++;
	ll q,w,e;
	cin>>q>>w>>e;
	if(!q&&!w&&!e)exit(0);
	LiChao lct;
	lct.init(0,2e9);
	lct.insert(0,line(0,w));
	vector<mach> v(q);
	for(int i=0;i<q;i++)cin>>v[i].d>>v[i].p>>v[i].r>>v[i].g;
	sort(v.begin(),v.end());
	for(int i=0;i<q;i++){
		ll d,p,r,g;
		d=v[i].d;p=v[i].p;r=v[i].r;g=v[i].g;
		cout<<"|"<<d<<" "<<p<<" "<<r<<" "<<g<<"\n";
		ll k=lct.get(0,d);
		if(k>=p)lct.insert(0,line(g,-d*g+k-p+r));
	}
	cout<<"Case "<<tccnt<<": "<<lct.get(0,e+1)<<"\n";
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	while(1){
		TC();
	}
}
