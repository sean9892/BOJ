#include<bits/stdc++.h>
using namespace std;

using ll=long long;

int n,q;
ll s,t;
ll a[200010];
ll d[200010];
ll res=0;

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q>>s>>t;
	for(int i=0;i<=n;i++){
		cin>>a[i];
		if(i){
			d[i-1]=a[i]-a[i-1];
			if(d[i-1]>0)res-=s*d[i-1];
			else res-=t*d[i-1];
		}
	}
	for(int i=0;i<q;i++){
		int l,r;
		ll x;
		cin>>l>>r>>x;
		if(l!=0){
			if(d[l-1]>0)res+=s*d[l-1];
			else res+=t*d[l-1];
			d[l-1]+=x;
			if(d[l-1]>0)res-=s*d[l-1];
			else res-=t*d[l-1];
		}
		if(r!=n){
			if(d[r]>0)res+=s*d[r];
			else res+=t*d[r];
			d[r]-=x;
			if(d[r]>0)res-=s*d[r];
			else res-=t*d[r];
		}
		cout<<res<<"\n";
	}
}
