#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int s=0;
	for(int i=0;i<n;i++){
		s+=a[i]*b[n-i-1];
	}
	cout<<s;
}
