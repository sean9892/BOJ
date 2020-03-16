#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#include<immintrin.h>
using namespace std;
using ll=unsigned long long;

ll N,P;
ll K,R;

__m256i getHi_epi64(__m256i x){
	return _mm256_srli_epi64(x,32);
}

__m256i getLo_epi64(__m256i x){
	return getHi_epi64(_mm256_slli_epi64(x,32));
}

__m256 abmodp(__m256i x,__m256i y){
	__m256i xh=getHi_epi64(x),xl=getLo_epi64(x);
	__m256i yh=getHi_epi64(y),yl=getLo_epi64(y);
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
}
