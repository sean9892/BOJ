#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int arr[1000010];
int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	ll a,b;
	cin>>a>>b;
	ll c=b-a+1;
	for(ll i=2;i*i<=b;i++){
		ll s=i*i;
		for(ll j=(a-1)/s+1;s*j<=b;j++){
			c-=!arr[s*j-a];
			arr[s*j-a]=1;
		}
	}
	cout<<c;
}
