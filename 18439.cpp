#pragma GCC optimize O("O3")
#pragma GCC optimize O("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
#define get(v,x) ((((v)[x/64]>>(x&63))&1)==1)
#define set(v,x) ((v)[x/64]|=1llu<<(x&63))

int f(ll &x,ll y){
	ll t=x;
	x=t-y;
	return x>t;
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	string a,b;
	cin>>a>>b;
	int n=a.size(),m=b.size();
	int sz=m/64+1;
	vector<ll> s[256],row(sz);
	for(int i=0;i<256;i++)s[i].resize(sz);
	for(int i=0;i<m;i++)set(s[b[i]],i);
	for(int i=0;i<m;i++)if(a[0]==b[i]){
		set(row,i);break;
	}
	for(int i=1;i<n;i++){
		ll aa=1,bb=0;
		for(int j=0;j<sz;j++){
			ll x=s[a[i]][j]|row[j];
			ll q=(row[j]<<1)|aa,w=x;
			aa=row[j]>>63;
			bb=f(w,bb);bb+=f(w,q);
			row[j]=x&(x^w);
		}
		row[m/64]&=(1llu<<(m&63))-1;
	}
	int r=0;
	for(int i=0;i<m;i++)if(get(row,i)){
		r++;
	}
	cout<<r<<"\n";
	
}
