#include<bits/stdc++.h>
using namespace std;

int arr[2000010];
int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int m=(n+1)/2;
    for(int i=0;i<m;i++){
        sum+=31-__builtin_clz(arr[i]);
    }
    cout<<sum+1;
}