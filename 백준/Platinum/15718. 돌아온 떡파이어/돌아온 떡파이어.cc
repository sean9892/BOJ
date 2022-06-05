#include<bits/stdc++.h>
using namespace std;

int ncr97[99][99];
int ncr1031[1099][1099];

int f97(int n,int r){
    int res=1;
    while(n||r){
        res*=ncr97[n%97][r%97];
        n/=97;
        r/=97;
        res%=97;
    }
    return res;
}

int f1031(int n,int r){
    int res=1;
    while(n||r){
        res*=ncr1031[n%1031][r%1031];
        n/=1031;
        r/=1031;
        res%=1031;
    }
    return res;
}

void TC(){
    int N,M;
    cin>>N>>M;
    --M;
    if(N<M){
        cout<<"0\n";
        return;
    }
    if(M==0){
        if(N==0){
            cout<<"1\n";
        }
        else{
            cout<<"0\n";
        }
        return;
    }
    if(M==N){
        cout<<"1\n";
        return;
    }
    int x=f97(N-1,M-1),y=f1031(N-1,M-1);
    int r=(36085*x%100007+63923*y%100007)%100007;
    cout<<r<<"\n";
}

int32_t main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    ncr97[0][0]=ncr1031[0][0]=1;
    for(int i=1;i<97;i++){
        ncr97[i][0]=1;
        for(int j=1;j<=i;j++){
            ncr97[i][j]=ncr97[i-1][j-1]+ncr97[i-1][j];
            ncr97[i][j]%=97;
        }
    }
    for(int i=1;i<1031;i++){
        ncr1031[i][0]=1;
        for(int j=1;j<=i;j++){
            ncr1031[i][j]=ncr1031[i-1][j-1]+ncr1031[i-1][j];
            ncr1031[i][j]%=1031;
        }
    }
    int T;
    cin>>T;
    while(T--){
        TC();
    }
}