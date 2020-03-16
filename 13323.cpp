#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	vector<int> v(n+1);
	priority_queue<int> q;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		x-=i;
		q.push(x);q.push(x);q.pop();
		v[i]=q.top();
	}
	for(int i=n-1;i>0;i--)v[i]=min(v[i],v[i+1]);
	for(int i=1;i<=n;i++)cout<<v[i]+i<<"\n";
}
