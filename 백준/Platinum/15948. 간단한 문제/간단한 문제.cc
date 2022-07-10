#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,m;
ll A[99];
ll x[99];

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>A[i];
    }
    for(int i=m;i>0;i--){
        if(n%2==1){
            x[i]=n;
            n=(n+1)/2;
        }else{
            x[i]=n+(1ll<<i)-2;
            n=n/2;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<A[i]*x[i]<<" ";
    }
}