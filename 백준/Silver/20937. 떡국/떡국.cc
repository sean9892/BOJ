#include<bits/stdc++.h>
using namespace std;

int cnt[50010];

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        cnt[x]++;
    }
    int r=0;
    for(int i=1;i<=50000;i++){
        r=max(r,cnt[i]);
    }
    cout<<r;
}