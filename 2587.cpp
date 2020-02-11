#include<bits/stdc++.h>
using namespace std;

int main(void){
	vector<int> v;
	int x=0;
	for(int i=0;i<5;i++){
		int t;
		cin>>t;
		v.push_back(t);
		x+=t/5;
	}
	sort(v.begin(),v.end());
	cout<<x<<"\n"<<v[2];
}
