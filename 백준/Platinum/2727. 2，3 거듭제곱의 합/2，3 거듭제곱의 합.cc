#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void TC(){
    ll n;
    cin>>n;
    int b2=0;
    vector<int> v,w;
    while(n>0){
        while(n%2==0){
            b2++;
            n/=2;
        }
        ll r=1;
        int i;
        for(i=0;r<=n;i++,r*=3);
        r/=3;i--;
        n-=r;
        v.push_back(b2);
        w.push_back(i);
    }
    cout<<v.size()<<"\n";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" "<<w[i]<<"\n";
    }
}

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    int tc;
    cin>>tc;
    while(tc--){
        TC();
    }
}