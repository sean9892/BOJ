#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int l;
	cin>>l;
	for(int i=0;i<l;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	v.push_back(0);
	sort(v.begin(),v.end());
	int n;
	cin>>n;
	for(int i=0;i<l;i++)if(v[i]==n){
		cout<<0;
		return 0;
	}
	int i;
	for(i=0;i<l&&v[i]<n;i++);
	--i;
	cout<<(n-v[i])*(v[i+1]-n)-1;
}
