#include<bits/stdc++.h>
using namespace std;

int main(void){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)cin>>v[i];
	int x;
	cin>>x;
	int cnt=0;
	for(int i:v)if(i==x)cnt++;
	cout<<cnt;
}
