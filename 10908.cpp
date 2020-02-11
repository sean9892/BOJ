#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct mat{
	ll a,b;
	ll c,d;
	mat(ll x=0,ll y=0,ll z=0,ll w=0):a(x),b(y),c(z),d(w){}
};

const ll mod=1e9+7;

mat operator*(mat x,mat y){
	return mat((x.a*y.a%mod+x.b*y.c%mod+mod)%mod,	(x.a*y.b%mod+x.b*y.d%mod+mod)%mod,
	           (x.c*y.a%mod+x.d*y.c%mod+mod)%mod,	(x.c*y.b%mod+x.d*y.d%mod+mod)%mod
	);
}

mat matPow(mat x,ll n){
	if(n==0)return mat(1,0,0,1);
	if(n==1)return x;
	if(n&1)return matPow(x*x,n/2)*x;
	return matPow(x*x,n/2);
}

ll ipow(ll x,ll n){
	if(n==0)return 1;
	if(n==1)return x;
	if(n&1)return ipow(x*x%mod,n/2)*x%mod;
	return ipow(x*x%mod,n/2)%mod;
}

int main(void){
	ll n,k;
	cin>>n>>k;
	if(!n||!k){
		cout<<"0 1";
		return 0;
	}
	mat x=matPow(matPow({1,1,1,0},n),k),y=matPow({1,1,1,0},k);
	ll a=x.b*ipow(y.b,mod-2)%mod;
	if(y.b==0){
		if(n==1){
			a=1;
		}
		else{
			mat z=matPow({1,1,1,0},k-1)*mat({4,3,3,1});
			ll t=z.d;
			ll pl=k&1?1:mod-1;
			mat w=matPow({t,pl,1,0},n-2)*mat({(t*((t*t%mod+pl)%mod)+pl*t)%mod,(t*t%mod+pl)%mod,(t*t%mod+pl)%mod,t});
			a=w.d;
		}
	}
	ll b=(x.d-a*y.d%mod+mod)%mod;
	cout<<a<<" "<<b<<"\n";
}

