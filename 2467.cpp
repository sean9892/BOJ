#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)cin>>v[i];
	int l=0,r=n-1;
	int x,y;
	int mv=2e9+10;
	while(l<r){
		if(mv>abs(v[l]+v[r])){
			mv=abs(v[l]+v[r]);
			x=l;y=r;
		}
		if(v[l]+v[r]<0)l++;
		else r--;
	}
	cout<<v[x]<<" "<<v[y];
}
