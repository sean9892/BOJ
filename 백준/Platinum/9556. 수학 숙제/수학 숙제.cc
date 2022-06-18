#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll

const ll MOD = 1000000007;

ll ipow(ll a,ll n,const int mod){
    if(n==1)return a;
    if(n==2)return 1ll*a*a%mod;
    ll res=ipow(a*a%mod,n/2,mod);
    if(n%2)res=res*a%mod;
    return res;
}

struct matrix{
    ll a,b;
    ll c,d;
    matrix operator*(const matrix t){
        return {(a*t.a%MOD+b*t.c%MOD)%MOD,(a*t.b%MOD+b*t.d%MOD)%MOD,(c*t.a%MOD+d*t.c%MOD)%MOD,(c*t.b%MOD+d*t.d%MOD)%MOD};
    }
};

matrix mpow(matrix a,int n){
    if(n==0)return {1,0,0,1};
    if(n==1)return a;
    if(n==2)return a*a;
    matrix r=mpow(a*a,n/2);
    if(n%2)r=r*a;
    return r;
}

void tc(){
    ll n;
    scanf("%lld",&n);
    if(n<=3){
        int x[7];
        for(int i=1;i<=6;i++){
            scanf("%1d",&x[i]);
        }
        int cnt=0;
        for(int i=0;i<(n==1?10:(n==2?100:1000));i++){
            int c=0;
            for(int j=1;j<=6;j++){
                c+=((x[j]==0&&i%j!=0)||(x[j]==1&&i%j==0)||(x[j]==2));
            }
            cnt+=(c==6);
        }
        printf("%lld\n",cnt);
        return;
    }
    int arr[120]={1,};
    for(int i=0;i<120;i++)arr[i]=1;
    for(int i=1;i<=6;i++){
        int x;
        scanf("%1lld",&x);
        if(x==0){
            for(int j=0;j<120;j++)if(j%i==0)arr[j]=0;
        }
        if(x==1){
            for(int j=0;j<120;j++)if(j%i!=0)arr[j]=0;
        }
    }
    matrix m = mpow({10,3,0,1},n-3);
    ll r = (m.a*8+m.b)%MOD;
    ll x1=0, x2=0;
    for(int i=0;i<120;i++){
        x1+=arr[i];
    }
    for(int i=0;i<40;i++){
        x2+=arr[i];
    }
    printf("%lld\n",(x1*r%MOD+x2)%MOD);
}

int32_t main(void){
    int TC;
    scanf("%lld",&TC);
    while(TC--){
        tc();
    }
}