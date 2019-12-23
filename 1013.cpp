#include<bits/stdc++.h>
using namespace std;

void TC(){
    string s;
    cin>>s;
    cout<<(regex_match(s,regex("(100+1+|01)+"))?"YES":"NO")<<"\n";
}

int main(void){
    int tc;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>tc;
    while(tc--){
        TC();
    }
}
