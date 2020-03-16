#include<bits/stdc++.h>
using namespace std;

int n;
long long a[1010];

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long r=0x3f3f3f3f;
	for(int i=1;i<=1000;i++){
		long long c=0;
		for(int j=0;j<n;j++){
			c+=(a[j]!=(i+j*k));
		}
		r=min(r,c);
	}
	cout<<r;
}
