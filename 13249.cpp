#include<bits/stdc++.h>
using namespace std;

int main(void){
	int n;
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	int t;
	cin>>t;
	int cnt=0;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++)if(v[i]-v[j]<=2*t){
			cnt++;
		}
	}
	cout<<(double)cnt/(1<<n);
}
