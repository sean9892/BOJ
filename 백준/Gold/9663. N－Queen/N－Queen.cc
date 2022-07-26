#include<bits/stdc++.h>
using namespace std;

int n;
int f(int idx,int a,int b,int c){
    if(n==idx)return 1;
    int s=0;
    for(int i=0;i<n;i++){
        if((a&(1<<i))||(b&(1<<idx+i))||(c&(1<<idx+n-i)))continue;
        s+=f(idx+1,a|(1<<i),b|(1<<idx+i),c|(1<<idx+n-i));
    }
    return s;
}

int main(void){
    scanf("%d",&n);
    cout<<f(0,0,0,0);
}