#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll arr[300];
ll cnt[300];
ll sum[310];
ll csm[310];

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,b;
	cin>>n>>m>>b;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ll t;
			cin>>t;
			arr[t]+=t;
			cnt[t]++;
		}
	}
	for(int i=0;i<=300;i++){
		sum[i+1]=sum[i]+arr[i];
		csm[i+1]=csm[i]+cnt[i];
	}
	ll mt=1e18;
	ll h=-1;
	for(int i=256;i>=0;i--){
		ll ov=sum[257]-sum[i+1];
		ll un=sum[i+1];
		ll bb=csm[257]-csm[i+1];
		ll nd=csm[i+1]*i-un;
		if(nd>ov-bb*i+b)continue;
		ll tm=(ov-bb*i)*2+nd;
		if(mt>tm){
			h=i;
			mt=tm;
		}
	}
	cout<<mt<<" "<<h;
}
