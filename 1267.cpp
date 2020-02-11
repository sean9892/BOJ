#include<bits/stdc++.h>
using namespace std;

int main(void){
	int n;
	vector<int> v;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	int y=0,m=0;
	for(int i=0;i<n;i++){
		y+=(v[i]/30+1)*10;
		m+=(v[i]/60+1)*15;
	}
	if(y<=m)cout<<"Y ";
	if(m<=y)cout<<"M ";
	cout<<min(y,m);
}
