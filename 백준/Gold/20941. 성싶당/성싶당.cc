#include<bits/stdc++.h>
using namespace std;

string f(string p,int n){
    if(n==1){
        cout<<p<<"\n";
        for(int i=0;i<p.size();i++)p[i]^=1;
        cout<<p<<"\n";
        return p;
    }
    p=f(p,n-1);
    p[n-1]^=1;
    for(int i=0;i<p.size();i++)p[i]^=1;
    p=f(p,n-1);
    return p;
}

int main(void){
    int n;
    string p;
    cin>>n>>p;
    f(p,n);
}