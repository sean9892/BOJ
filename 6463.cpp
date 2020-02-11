#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(void){
	int n;
	while(scanf("%lld",&n)==1){
		int x=1;
		for(int i=1;i<=n;i++){
			x*=i;
			while(x%10==0)x/=10;
			cout<<x%10<<" ";
		}
		printf("%5lld -> %lld\n",n,x%10);
	}
}
