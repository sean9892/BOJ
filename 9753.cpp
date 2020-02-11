#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int p[100010];
vector<ll> pr;
vector<ll> v;
int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
    for(int i=2;i<50010;i++)if(!p[i]){
        pr.push_back(i);
        for(int j=2*i;j<50010;j+=i)p[j]=1;
    }
    for(int i=0;i<pr.size();i++)for(int j=0;j<i;j++){
    	if(pr[i]*pr[j]>100001)break;
    	v.push_back(pr[i]*pr[j]);
	}
    sort(v.begin(),v.end());
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        cout<<*lower_bound(v.begin(),v.end(),n)<<"\n";
    }
}
