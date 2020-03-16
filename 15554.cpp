#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;

#define fi first
#define se second

vector<pii> v;
ll dp[500010];

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	v.resize(n);
	for(int i=0;i<n;i++){
		cin>>v[i].fi>>v[i].se;
	}
	sort(v.begin(),v.end());
	v.push_back(pii(0,0));
	ll sum=0;
	ll res=0;
	ll lo=v[0].fi,hi=v[0].fi;
	for(int i=0;i<n;i++){
		sum+=v[i].se;
		hi=v[i].fi;
		res=max(res,sum-hi+lo);
		lo=max(lo,v[i+1].fi-sum);
	}
	cout<<res;
}
