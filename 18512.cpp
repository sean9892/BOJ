#include<bits/stdc++.h>
using namespace std;
using ll=long long;
set<ll> s;

int main(void){
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	for(ll i=0;i<10010;i++){
		s.insert(c);
		c+=a;
	}
	for(ll i=0;i<10010;i++){
		if(s.find(d)!=s.end()){
			cout<<d;
			return 0;
		}
		d+=b;
	}
	cout<<-1;
}
