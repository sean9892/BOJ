#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,p;

ll nfmodp(ll n,ll p){
	ll r=1;
	for(ll i=2;i<=n;i++){
		r*=i;
		r%=p;
	}
	return r;
}

ll ipow(ll x,ll n){
	ll r=1;
	while(r){
		if(r&1)r=r*n%p;
		n=n*n%p;
		r>>=1;
	}
	return r;
}

int main(void){
	scanf("%lld%lld",&n,&p);
	if(n>n-p){
		ll f=nfmodp(p-n-1,p);
		if((p-n)%2==0)f=p-f;
		printf("%lld",((p-1)*ipow(f,p-2))%p);
	}
	else{
		printf("%lld",nfmodp(n,p));
	}
}
