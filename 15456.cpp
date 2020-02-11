#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+10;
int n;
int v[nmax];
int a[nmax];

bool f(int k){
	memset(a,0,sizeof(a));
	for(int i=1;i<k;i++)a[v[i]]++;
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(sum>=i)return false;
	}
	return true;
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		v[i]=n-v[i];
	}
	int lo=1,hi=n+1;
	while(lo+1<hi){
		int m=lo+hi>>1;
		if(f(m))lo=m;
		else hi=m;
	}
	cout<<n-lo;
}
