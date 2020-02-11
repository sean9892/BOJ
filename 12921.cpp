#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int n;
ll x,a,b;
const ll mod=1e9+7;

int q;
int qv[1010];
ll lo[1010],hi[1010],mid[1010];
int r[1010];

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	fill(r,r+1010,-1);
	cin>>n>>x>>a>>b;
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>qv[i];qv[i]++;
		lo[i]=0;hi[i]=mod-1;
		mid[i]=lo[i]+hi[i]>>1;
	}
	sort(qv,qv+q);
	int fin=0;
	while(!fin){
		int d[q+1]={0};
		fin=1;
		ll v=x;
		for(int i=0;i<n;i++){
			int r=lower_bound(mid,mid+q,v)-mid;
			d[r]++;
			v=(v*a+b)%mod;
		}
		int cnt=0;
		for(int i=0;i<q;i++){
			cnt+=d[i];
			if(lo[i]==hi[i])continue;
			if(cnt>qv[i])hi[i]=mid[i]-1;
			else if(cnt==qv[i])hi[i]=mid[i];
			else lo[i]=mid[i]+1;
			mid[i]=lo[i]+hi[i]>>1;
			if(lo[i]!=hi[i])fin=0;
		}
	}
	ll sum=0;
	for(int i=0;i<q;i++){
		sum+=lo[i];
	}
	cout<<sum;
}
