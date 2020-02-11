#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll v[100010];

ll f(ll x){
	ll r=0;
	for(ll i=1;i*i<=x;i++)r+=v[i]*(x/(i*i));
	return r;
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	fill(v,v+100010,1);
	int n;
	cin>>n;
	for(ll i=2;i*i<100010;i++){
		if(v[i]==1){
			for(ll j=1;i*j<=100010;j++)v[i*j]*=-i;
			for(ll j=1;i*i*j<100010;j++)v[i*i*j]=0;
		}
	}
	for(ll i=2;i<100010;i++){
		#define elif else if
		if(v[i]==i)v[i]=1;
		elif(v[i]==-i)v[i]=-1;
		elif(v[i]<0)v[i]=1;
		elif(v[i]>0)v[i]=-1;
		#undef elif
	}
	ll lo=1,hi=2e9;
	while(lo<hi){
		ll m=(lo+hi)>>1;
		ll r=f(m);
		if(r>n)hi=m-1;
		else if(r==n)hi=m;
		else lo=m+1;
	}
	cout<<lo;
}
