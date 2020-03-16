#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void TC(){
	int n,m;
	vector<ll> a,b;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		ll x;cin>>x;
		a.push_back(x);
	}
	for(int i=0;i<m;i++){
		ll x;cin>>x;
		b.push_back(x);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int p=0;
	ll sum=0;
	for(int i=0;i<n;i++){
		while(p<m&&b[p]<a[i])p++;
		ll r=-0x3f3f3f3f;
		if(p){
			if(abs(a[i]-r)>abs(a[i]-b[p-1]))r=b[p-1];
		}
		if(p<m){
			if(abs(a[i]-r)>abs(a[i]-b[p]))r=b[p];
		}
		if(p+1<m){
			if(abs(a[i]-r)>abs(a[i]-b[p+1]))r=b[p+1];
		}
		sum+=r;
	}
	cout<<sum<<"\n";
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
		TC();
	}
}
