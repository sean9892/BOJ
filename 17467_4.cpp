#include<bits/stdc++.h>
#include<immintrin.h>
using namespace std;
using ll=long long;

ll nfmodp(ll N,ll P){
	__m256 res=_mm256_set_epi64(1,1,1,1);
	__m256 mul=_mm256_set_epi64(1,2,3,4);
	__m256 add=_mm256_set_epi64(4,4,4,4);
	__m256 mod=_mm256_set_epi64(P,P,P,P);
	for(ll i=0;i<N/4;i++){
		res=_mm256_mul_epi64(res,mul);
		mul=_mm256_add_epi64(mul,add);
		res=_mm256_sub_epi64(res,_mm256_mul_epi64(_mm256_div_epi64(res,mod),mod));
	}
	ll* r=&res;
	ll rr=r[0]*r[1]%P*r[2]%P*r[3]%P;
	for(ll i=N/4*4+1;i<=N;i++){
		rr*=i;
		rr%=P;
	}
	return rr;
}

ll ipow(ll x,ll n){
	if(n==1)return x;
	if(n==0)return 1;
	if(n&1)return ipow(x*x,n/2)*x%p;
	return ipow(x*x,n/2);
}

int main(void){
	ll n,p;
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>p;
	if(n>n-p){
		ll f=nfmodp(p-n-1,p);
		if((p-n)%2==0)f=p-f;
		cout<<((p-1)*ipow(f,p-2))%p;
	}
	else{
		cout<<nfmodp(n,p);
	}
}
