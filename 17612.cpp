#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pi3=pair<pii,ll>;

#define fi first
#define se second

int n,k;
vector<pii> v;

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	v.resize(n);
	for(int i=0;i<n;i++)cin>>v[i].fi>>v[i].se;
	priority_queue<pii> q;
	for(int i=1;i<=k;i++){
		q.push(pii(0,-i));
	}
	priority_queue<pi3> w;
	for(int i=0;i<n;i++){
		auto x=q.top();q.pop();
		q.push(pii(x.fi-v[i].se,x.se));
		w.push(pi3(pii(x.fi-v[i].se,-x.se),v[i].fi));
	}
	ll r=0;
	for(int i=1;i<=n;i++){
		r+=w.top().se*i;w.pop();
	}
	cout<<r;
}
