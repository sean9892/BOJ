#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,k;
    cin>>n>>k;
    int m=n;
    while(__builtin_popcount(n)>k)n++;
    cout<<n-m;
}