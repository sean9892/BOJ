#include<bits/stdc++.h>
using namespace std;
using ll=long long;
template<typename T>
class LinearMinCHT{
	public:
		vector< pair<T, T> > stk;
		long long idx;
	
		double cross(long long a, long long b){
			double t1 = (double)(stk[b].second - stk[a].second);
			double t2 = (double)(stk[a].first - stk[b].first);
			return t1/t2;
		}
		
		void insert(T a, T b){
			stk.emplace_back(a, b);
			while(stk.size() > 2 &&
			cross(stk.size()-3, stk.size()-2) > cross(stk.size()-2, stk.size()-1)){
				stk[stk.size()-2] = stk.back();
				stk.pop_back();
			}
		}
		
		T query(T x){
			while(idx+1 < stk.size() && cross(idx, idx+1) <= x){
				idx++;
			}
			return x*stk[idx].first + stk[idx].second;
		}
		
		LinearMinCHT(){
			idx = 0; stk.clear();
		}
};
ll dp[1000010];
ll s[1000010];
int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    LinearMinCHT<ll> lc;
    lc.insert(b,0);
    for(int i=1;i<=n;i++){
        cin>>s[i];
        s[i]+=s[i-1];
        dp[i]=c+a*s[i]*s[i]+lc.query(s[i]);
        lc.insert(-2*a*s[i]+b,dp[i]-b*s[i]+a*s[i]*s[i]);
    }
    cout<<dp[n];
}