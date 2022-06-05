#include<bits/stdc++.h>
using namespace std;

int arr[110][110];

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;
            cin>>x;
            arr[i][j]+=x;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;
            cin>>x;
            arr[i][j]+=x;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}