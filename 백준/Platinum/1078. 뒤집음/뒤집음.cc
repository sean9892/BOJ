#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll ipow(ll a,int n){
    if(n==0)return 1;
    if(n==1)return a;
    if(n==2)return a*a;
    ll res = ipow(a*a,n/2);
    if(n%2)res *= a;
    return res;
}

ll f(ll D,int l){
    ll res = 0;
    ll Dp=D;
    for(int i=0;2*i<l;i++){
        if(D%10>0||(D%10==0&&i!=0))res += D%10*ipow(10,l-i);
        if(D%10==0&&i==0)res += ipow(10,l-i)+(l-i!=i)*ipow(10,i);
        if(D%10<0)res -= D%10*ipow(10,i);
        D-=D%10*(ipow(10,l-2*i)-1)/9;
        D/=10;
    }
    if(D)return -1;
    else return res;
}

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    ll D;
    cin>>D;
    if(D%9){
        cout<<"-1";
        return 0;
    }
    D/=9;
    for(int i=1;i<=17;i++){
        ll r = f(D,i);
        if(r!=-1){
            cout<<r;
            return 0;
        }
    }
    cout<<"-1";
    return 0;
}