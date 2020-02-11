#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using big=vector<ll>;

big ncr[110][110];
const ll mod=10;

big add(big a,big b){
	if(a.size()<b.size())swap(a,b);
	a.resize(a.size()+1);
	b.resize(a.size()+1);
	big r(a.size()+1);
	for(int i=0;i<=a.size();i++){
		r[i]=a[i]+b[i];
		if(r[i]>=mod)a[i+1]+=r[i]/mod;
		r[i]%=mod;
	}
	while(!r.back())r.pop_back();
	return r;
}

big bigi(ll x){
	return big(x,1);
}

void print(int n,int m){
	stack<ll> s;
	for(ll i:ncr[n][m])s.push(i);
	while(!s.empty())cout<<s.top(),s.pop();
}

int main(void){
	for(int i=0;i<101;i++){
		ncr[i][0]=bigi(1);
		for(int j=1;j<=i;j++){
			ncr[i][j]=add(ncr[i-1][j-1],ncr[i-1][j]);
		}
	}
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			print(i,j);cout<<" ";
		}
		cout<<"\n";
	}
	for(ll i:add(bigi(9),bigi(1)))cout<<i<<" ";
}
