#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;

map<pii,int> mem;

int f(ll s,ll e){
	if(!s&&!e)return 0;
	if(mem.find(pii(s,e))!=mem.end())return mem[pii(s,e)];
	int res=0;
	for(int i=1;i<35;i++){
		ll x=(1ll<<i);
		ll l=max(s,x-1);
		ll r=min(e,x*2-2);
		if(l<=r)res=max(res,f(l-x+1,r-x+1)+i);
	}
	return mem[pii(s,e)]=res;
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
		int l,r;
		cin>>l>>r;
		cout<<f(l,r)<<"\n";
	}
}
