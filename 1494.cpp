#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

map<int,int> dp;

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int a,b,tc;
	cin>>a>>b>>tc;
	if(a==b){
		while(tc--){
			int n;
			cin>>n;
			if(n%3==0)cout<<"0\n";
			else cout<<a<<"\n";
		}
		return 0;
	}
	dp[1]=a;dp[2]=b;
	if(a>b){
		
	}
	else{
		
	}
}
