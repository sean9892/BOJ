#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	vector<int> v;
	vector<pii> w;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
		w.emplace_back(x,0);
	}
	sort(w.begin(),w.end());
	long long sum=0;
	for(int i=0;i<n;i++){
		int l=lower_bound(w.begin(),w.end(),pii(v[i],0))-w.begin();
		sum+=abs(l-i);
		w[l].first--;
	}
	cout<<sum;
}
