#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loop")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define endl '\n'
#define y1 holyshit
#define all(x) x.begin(),x.end()
const int inf=0x3f3f3f3f;


static inline int _read(){
    
}

int v[1024000];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,l;
    vector<vector<ll>> v;
    cin>>n>>l;
    vector<int> dp(l+1);
    v.resize(n,vector<ll>(l));
    for(int i=0;i<n;i++) for(int j=0;j<l;j++){
        cin>>v[i][j];
    }
    srand(time(NULL));
    auto mul = [&](int a,int b,vector<ll>&t){
        vector<ll> ans(n);
        for(int i=0;i<n;i++){
            ll&s = ans[i];
            for(int j=0;j<n;j++){
                s += v[i+a][j+b] * t[j]; 
            }
        }
        return ans;
    };
    auto chk = [&](int k){
        int a = k - 3*n + 1;
        int b = a + n;
        int c = b + n;
        int cnt = 5;
        while(cnt--){
            vector<ll> f(n);
            for(int i=0;i<n;i++) f[i] = rand()%197;
            vector<ll> f2 = mul(0, c, f);
            vector<ll> f3 = mul(0, b, f);
            for(int i=0;i<n;i++){
                ll s = 0;
                for(int j=0;j<n;j++){
                    s += v[i][j+a] * f3[j]; 
                }
                if(s != f2[i]) return false;
            }
        }
        return true;
    };
    for(int i=3*n;i<=l;i++){
        dp[i] = dp[i-1];
        if(chk(i-1)){
            dp[i] = max(dp[i], dp[i-3*n] + 1);
        }
    }
    cout<< 1LL * dp[l]* 3 * n * n;
    return 0;
}