#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii=pair<ll,ll>;
#define fi first
#define se second

const ll MOD = 1e9 + 7;

ll fib[1000010];
pii swp[1000010];

void ADD(int idx,ll a,ll b){
  ll x=swp[idx].fi;
  ll y=swp[idx].se;
  x=(x+a)%MOD;
  y=(y+b)%MOD;
  swp[idx]=pii(x,y);
}

int main(void) {
  ios::sync_with_stdio(0);cin.tie(0);
  fib[0]=0;fib[1]=1;
  for (int i=2;i<=1000005;i++) {
    fib[i]=(fib[i-1]+fib[i-2])%MOD;
  }
  int N, Q;
  cin>>N>>Q;
  for(int i=0;i<Q;i++){
    int l,r;
    cin>>l>>r;
    ADD(l,0,1);
    ADD(r+1,MOD-fib[r-l+1],MOD-fib[r-l+2]);
  }
  pii s(0,0);
  for(int i=1;i<=N;i++){
    s = pii(s.se,(s.fi+s.se)%MOD);
    s = pii((s.fi+swp[i].fi)%MOD,(s.se+swp[i].se)%MOD);
    cout<<s.se<<" ";
  }
}