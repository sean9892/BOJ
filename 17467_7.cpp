#pragma GCC target("sse2,avx,avx2,fma")
#include<bits/stdc++.h>
#include<immintrin.h>
#include<emmintrin.h>
using namespace std;
using uint=unsigned int;

uint x,p;
uint N,M,R,S,T,qL;

__m128i _mul(__m128i x,__m128i y){
	__m128i P=_mm_set_epi32(p,p,p,p);
	__m128i QL=_mm_set_epi32(qL,qL,qL,qL);
	__m128i al=_mm_mul_epu32(x,y);
	__m128i bl=_mm_srli_epi64(al,S);
	__m128i cl=_mm_srli_epi64(_mm_mullo_epi32(bl,QL),T);
	__m128i xh=_mm_srli_si128(x,4);
	__m128i yh=_mm_srli_si128(y,4);
	__m128i ah=_mm_mul_epu32(xh,yh);
	__m128i bh=_mm_srli_epi64(ah,S);
	__m128i ch=_mm_srli_epi64(_mm_mullo_epi32(bh,QL),T);
	__m128i a=_mm_blend_epi16(al,_mm_slli_si128(ah,4),4+8+64+128);
	__m128i c=_mm_or_si128(cl,_mm_slli_si128(ch,4));
	__m128i d=_mm_sub_epi32(a,_mm_mullo_epi32(c,P));
	return _mm_min_epu32(d,_mm_sub_epi32(d,P));
}

uint nfmodp(uint x){
	__m128i res=_mm_set_epi32(1,1,1,1);
	__m128i mul=_mm_set_epi32(1,2,3,4);
	__m128i add=_mm_set_epi32(4,4,4,4);
	uint i;
	for(i=4;i<=x;i+=4){
		res=_mul(res,mul);
		mul=_mm_add_epi32(mul,add);
	}
	alignas(32) uint rr[4];
	_mm_store_si128((__m128i*)rr,res);
	long long rrr=(long long)rr[0]*rr[1]%p*rr[2]%p*rr[3]%p;
	for(i-=3;i<=x;i++)rrr=rrr*i%p;
	return (uint)rrr;
}

uint ipow(uint x,int n){
	if(n==1)return x;
	if(n==0)return 1;
	if(n&1)return (uint)((long long)ipow((uint)((long long)x*x%p),n/2)*x%p);
	return ipow((uint)((long long)x*x%p),n/2);
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>x>>p;
	N=32;
	for(R=0;(1<<R)<p;R++);
	for(M=0;(1<<M)<=p;M++);
	if(M<N-1){
		S=max(R-2,0u);
		T=N+1;
	}
	else if(M<N){
		S=R-1;
		T=N;
	}
	else{
		S=R-1;
		T=N;
	}
	qL=((1ll<<(S+T))+p-1)/p;
	if(x>p-x){
		uint f=nfmodp(p-x-1);
		if((p-x)%2==0)f=p-f;
		cout<<((long long)(p-1)*ipow(f,p-2))%p;
	}
	else{
		cout<<nfmodp(x);
	}
}
