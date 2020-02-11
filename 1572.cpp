#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll=long long;
using pii=pair<ll,ll>;
using ordset=tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>;

ordset s;
ll res;
int v[250010];
int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>v[i];
	for(int i=1;i<=k;i++)s.insert({v[i],i});
	res+=(*s.find_by_order((k+1)/2-1)).first;
	for(int i=k+1;i<=n;i++){
		s.erase({v[i-k],i-k});
		s.insert({v[i],i});
		res+=(*s.find_by_order((k+1)/2-1)).first;
	}
	cout<<res;
}
