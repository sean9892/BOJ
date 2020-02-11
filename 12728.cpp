#include<bits/stdc++.h>
using namespace std;

const int mod=1000;

int npow(int n,int k){
	if(k==1)return n;
	if(k==0)return 1;
	return npow(n*n%mod,k/2)%mod*((k&1)?n:1)%mod;
}

int f(int n){
	if(n==1)return 6;
	if(n&1)return (f(n/2)*f(n/2+1)%mod-6*npow(4,n/2)%mod+mod)%mod;
	else{
		int r=f(n/2);
		return (r*r-2*npow(4,n/2)%mod+mod)%mod;
	}
}

int main(void){
	int tc;
	scanf("%d",&tc);
	for(int i=1;i<=tc;i++){
		int n;
		scanf("%d",&n);
		printf("Case #%d: %03d\n",i,(f(n)-1+mod)%mod);
	}
}
