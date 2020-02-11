#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	vector<string> v(n);
	for(int i=0;i<n;i++)cin>>v[i];
	vector<int> c(v[0].size(),1);
	for(int i=1;i<n;i++){
		for(int j=0;j<v[0].size();j++){
			if(v[i][j]!=v[i-1][j])c[j]=0;
		}
	}
	for(int i=0;i<v[0].size();i++){
		if(c[i])cout<<v[0][i];
		else cout<<"?";
	}
}
