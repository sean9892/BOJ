#include<bits/stdc++.h>
using namespace std;

long long n,k;
int m;

int bi[2010][2010];

int main(void){
    cin>>n>>k>>m;
    for(int i=0;i<m;i++){
        bi[i][0]=1;
        for(int j=1;j<=i;j++)bi[i][j]=(bi[i-1][j]+bi[i-1][j-1])%m;
    }
    int r=1;
    while(n||k){
        r*=bi[n%m][k%m];
        n/=m;k/=m;
        r%=m;
    }
    cout<<r;
}
