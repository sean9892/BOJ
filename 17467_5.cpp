#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#include<immintrin.h>
using namespace std;
using ll=long long;

ll N,P;
ll K,R;
ll T;

ll nfmodp(ll n,ll p){
	__m256i rrr=_mm256_set_epi64x(R,R,R,R);
	__m256i ppp=_mm256_set_epi64x(p,p,p,p);
	__m256i pp2=_mm256_set_epi64x(p-1,p-1,p-1,p-1);
	__m256i res=_mm256_set_epi64x(1,1,1,1);
	__m256i mul=_mm256_set_epi64x(1,2,3,4);
	__m256i add=_mm256_set_epi64x(4,4,4,4);
	for(ll i=0;i<(n>>2);i++){
		res=_mm256_mul_epi32(res,mul);
		mul=_mm256_add_epi64(mul,add);
		{//Barrett reduction
			__m256i tmp=_mm256_mul_epi32(_mm256_srli_epi64(_mm256_mul_epi32(res,rrr),K<<1),ppp);
			res=_mm256_sub_epi64(res,tmp);
			res=_mm256_sub_epi64(res,_mm256_and_si256(_mm256_cmpgt_epi64(res,pp2),ppp));
		}
	}
	alignas(32) ll r[4];
	_mm256_store_si256((__m256i*)r,res);
	ll rr=r[0]*r[1]%p*r[2]%p*r[3]%p;
	for(ll i=((n>>2)<<2)+1;i<=n;i++){
		rr*=i;
		rr%=p;
	}
	return rr;
}

ll ipow(ll x,ll n){
	if(n==1)return x;
	if(n==0)return 1;
	if(n&1)return ipow(x*x%P,n/2)*x%P;
	return ipow(x*x%P,n/2);
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>N>>P;
	if(N==1){
		cout<<"1\n";
		return 0;
	}
	for(K=1;K<=P;K<<=1);
	R=(1<<2*K)/P;
	K%=P;
	R%=P;
	if(N>P-N){
		ll f=nfmodp(P-N-1,P);
		if((P-N)%2==0)f=P-f;
		cout<<((P-1)*ipow(f,P-2))%P;
	}
	else{
		cout<<nfmodp(N,P);
	}
}
