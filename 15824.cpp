#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=1e9+7;
ll pow2(ll x,int n){
	if(n<1)return 1;
	if(n==1)return x;
	return pow2(x*x%mod,n>>1)%mod*(n&1?x:1)%mod;
}
ll v[300010];
int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	ll sum=0;
	ll x=0;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>v[i];
	sort(v,v+n);
	x=v[0];
	for(ll i=1;i<n;i++){
		sum+=(v[i]*~-pow2(2,i)%mod-x+mod)%mod;
		sum%=mod;
		x=(x*2%mod+v[i]%mod)%mod;
	}
	cout<<sum;
}
