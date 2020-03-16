#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,k;
	cin>>n>>k;
	if(n<=k){
		cout<<n;
		return 0;
	}
	vector<int> v;
	vector<int> w;
	int sum=n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
		if(i){
			w.push_back(v[i]-v[i-1]-1);
			sum+=v[i]-v[i-1]-1;
		}
	}
	sort(w.begin(),w.end());
	for(int i=n-2,j=1;j<k;i--,j++){
		sum-=w[i];
	}
	cout<<sum;
}
