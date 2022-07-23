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

int a[30];
vector<ll> v[40];
ll arr[40][1<<16];
ll prf[40][1<<16];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    if(n<16){
        ll x=0;
        for(int i=(1<<n)-1;i>0;i--){
            ll s = 0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    s+=a[j];
                }
            }
            x^=s;
        }
        cout<<x;
        return 0;
    }
    for(int i=(1<<n/2)-1;i>=0;i--){
        ll s=0;
        for(int j=0;j<n/2;j++){
            if(i&(1<<j)){
                s+=a[j];
            }
        }
        for(int j=1;j<38;j++){
            ll t = s%(1ll<<j);
            v[j].push_back(t);
        }
    }
    for(int j=1;j<38;j++){
        sort(all(v[j]));
        v[j].erase(unique(all(v[j])),v[j].end());
    }
    for(int i=(1<<n/2)-1;i>=0;i--){
        ll s=0;
        for(int j=0;j<n/2;j++){
            if(i&(1<<j)){
                s+=a[j];
            }
        }
        for(int j=1;j<38;j++){
            ll t = s%(1ll<<j);
            arr[j][lower_bound(all(v[j]),t)-v[j].begin()]++;
        }
    }
    for(int j=1;j<38;j++){
        for(int i=0;i<v[j].size();i++){
            prf[j][i+1]=prf[j][i]+arr[j][i];
        }
    }
    const int m=n-n/2;
    ll res=0;
    for(int i=(1<<m)-1;i>=0;i--){
        ll s=0;
        for(int j=0;j<m;j++){
            if(i&(1<<j)){
                s+=a[j+n/2];
            }
        }
        for(int j=1;j<38;j++){
            ll t = s%(1ll<<j);
            ll cs = 0;
            ll tmp = (1ll<<(j-1));
            int aa = lower_bound(all(v[j]),tmp-t)-v[j].begin();
            int bb = lower_bound(all(v[j]),2*tmp-t)-v[j].begin();
            int cc = lower_bound(all(v[j]),3*tmp-t)-v[j].begin();
            int dd = lower_bound(all(v[j]),4*tmp-t)-v[j].begin();
            cs = prf[j][bb]-prf[j][aa]+prf[j][dd]-prf[j][cc];
            res^=(cs&1)*(1ll<<j-1);
        }
    }
    cout<<res;
    return 0;
}