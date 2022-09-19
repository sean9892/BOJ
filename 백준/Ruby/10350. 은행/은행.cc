#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int n;
ll arr[10101];
ll prf[101010];

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        prf[i]=prf[i-1]+arr[i];
    }
    for(int i=1;i<=n;i++){
        prf[i+n]=prf[i+n-1]+arr[i];
    }
    ll cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<i+n;j++){
            if(prf[j]-prf[i-1]<0){
                cnt+=(-prf[j]+prf[i-1]-1)/prf[n]+1;
            }
        }
    }
    cout<<cnt;
}