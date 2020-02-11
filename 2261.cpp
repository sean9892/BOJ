#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;

#define x first
#define y second

pii operator-(pii a,pii b){
	return {a.x-b.x,a.y-b.y};
}

ll eDist(pii a,pii b){
	pii r=a-b;
	return r.x*r.x+r.y*r.y;
}

int n;
const ll inf=1e16;

vector<pii> v;

struct cmp{
	bool operator()(pii& a,pii& b){
		return a.y<b.y;
	}
};

ll solve(int s,int n){
	if(n==2)return eDist(v[s],v[s+1]);
	if(n==3)return min({eDist(v[s],v[s+1]),eDist(v[s+1],v[s+2]),eDist(v[s+2],v[s])});
	ll piv=v[s+n/2-1].x+v[s+n/2].x>>1;
	ll d=min(solve(s,n/2),solve(s+n/2,n-n/2));
	vector<pii> w;
	for(int i=0;i<n;i++){
		ll t=piv-v[s+i].x;
		if(t*t<d)w.push_back(v[s+i]);
	}
	sort(w.begin(),w.end(),cmp());
	int ws=w.size();
	for(int i=0;i<ws-1;i++){
		for(int j=i+1;j<ws&&(w[j].y-w[i].y)*(w[j].y-w[i].y)<d;j++){
			d=min(eDist(w[j],w[i]),d);
		}
	}
	return d;
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	v.resize(n);
	for(int i=0;i<n;i++){
		cin>>v[i].x>>v[i].y;
	}
	sort(v.begin(),v.end());
	cout<<solve(0,n);
}
