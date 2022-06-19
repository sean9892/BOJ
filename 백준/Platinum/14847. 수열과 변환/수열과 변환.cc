#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const ll MOD = 1e9+7;

ll ipow(ll a,ll n,const ll mod){
    if(n==1)return a;
    if(n==2)return a*a%mod;
    ll r = ipow(a*a%mod,n/2,mod);
    if(n%2)r = r*a%mod;
    return r;
}

void TC(){
    ll n,m,q,k;
    cin>>n>>m>>q>>k;
    if(q>=m){
        cout<<"0\n";
        return;
    }
    ll r = (ipow(q+1,n,MOD)+ipow(q-1,n,MOD)-2*ipow(q,n,MOD)+2*MOD)%MOD;
    cout<<(m-q)*r%MOD<<"\n";
}

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--)TC();
}