#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	if(a<b)swap(a,b);
	if(b==0)return a;
	return gcd(b,a%b);
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	vector<int> v,w;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	int g=v[1]-v[0];
	w.push_back(v[1]-v[0]);
	for(int i=2;i<n;i++){
		g=gcd(g,v[i]-v[i-1]);
		w.push_back(v[i]-v[i-1]);
	}
	int cnt=0;
	for(int x:w)cnt+=x/g-1;
	cout<<cnt;
}
