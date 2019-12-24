#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int n;
ll arr[33];

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	mt19937 seed=mt19937((unsigned)chrono::steady_clock::now().time_since_epoch().count());
	cin>>n;
	uniform_int_distribution<int> rng(0,n-1);
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(char t:s){
			arr[i]<<=1;
			arr[i]|=(t=='H');
		}
	}
	int res=987654321;
	int a=0,b=0;
	int prv=n*n;
	double t=1,k=3;
	for(int i=0;i<10010;i++){
		b=a^(1<<rng(seed));
		int now=0;
		for(int j=0;j<n;j++){
			int t=__builtin_popcount(arr[j]^b);
			now+=min(t,n-t);
		}
		double p=exp((prv-now)/k*t);
		if(p>1.0*rng(seed)/(n-1)){
			a=b;prv=now;
		}
		res=min(res,prv);
		k*=0.9999;
	}
	cout<<res;
}
