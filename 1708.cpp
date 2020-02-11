#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
#define x first
#define y second

pii operator-(pii a,pii b){
	return {a.x-b.x,a.y-b.y};
}
ll cross(pii a,pii b){
	return b.y*a.x-b.x*a.y;
}
ll ccw(pii a,pii b,pii c){
	return cross(b-a,c-a);
}

vector<pii> ConvexHull(vector<pii> v){
	int nv=v.size(),k=0;
	if(nv<=3)return v;
	vector<pii> h(2*nv);
	sort(v.begin(),v.end());
	for(int i=0;i<nv;i++){
		while(k>=2&&ccw(h[k-2],h[k-1],v[i])<=0)k--;
		h[k++]=v[i];
	}
	for(int i=nv-1,t=k+1;i>0;i--){
		while(k>=t&&ccw(h[k-2],h[k-1],v[i-1])<=0)k--;
		h[k++]=v[i-1];
	}
	h.resize(k-1);
	return h;
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	vector<pii> v;
	for(int i=0;i<n;i++){
		ll a,b;
		cin>>a>>b;
		v.emplace_back(a,b);
	}
	cout<<ConvexHull(v).size();
}
