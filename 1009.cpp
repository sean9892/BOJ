#include<bits/stdc++.h>
using namespace std;

int ipow(int x,int n){
	if(n==1)return x;
	if(n==0)return 1;
	if(x==1)return 1;
	if(n&1)return ipow(x*x%10,n/2)*x%10;
	return ipow(x*x%10,n/2);
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		int x=ipow(a,b);
		if(!x)x=10;
		cout<<x<<"\n";
	}
}
