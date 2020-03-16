#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	ll n,k,q;
	cin>>n>>k>>q;
	while(q--){
		ll a,b;
		cin>>a>>b;
		if(k==1){
			if(a>b)swap(a,b);
			cout<<b-a<<"\n";
			continue;
		}
		--a;--b;
		int cnt=0;
		while(a!=b){
			if(a>b)swap(a,b);
			cnt++;
			b=(b-1)/k;
		}
		cout<<cnt<<"\n";
	}
}
