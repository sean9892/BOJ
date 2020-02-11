#include<bits/stdc++.h>
using namespace std;

int n,s;
vector<int> v;
int sum[100010];//sum([0,idx))
int res[100010];

int f(int st){
	int lo=0,hi=min(st+1,n-1-st);
	while(lo<=hi){
		int mid=lo+hi>>1;
		int a=sum[st+1]-sum[st-mid+1],b=sum[st+mid+1]-sum[st+1];
		if(a>s||b>s)hi=mid-1;
		else lo=mid+1;
	}
	return lo-1;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>s;
	v.resize(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
		sum[i+1]=v[i]+sum[i];
		res[i]=-1;
	}
	for(int i=0;i<n;i++){
		int r=f(i);
		//cout<<i<<" "<<r<<"\n";
		res[i-r+1]=max(res[i-r+1],2*r);
	}
	for(int i=0;i<n;i++){
		res[i]=max(max(0,res[i]),res[i-1]-2);
		cout<<res[i]<<"\n";
	}
}
