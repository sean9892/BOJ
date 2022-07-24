#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
#define fi first
#define se second

map<int,set<int>> lmp,rmp;
set<pii> s;

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        lmp[l].insert(r);
        rmp[r].insert(l);
        s.insert(pii(l,r));
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        if(s.find(pii(l,r))!=s.end()){
            cout<<"1\n";
        }
        else if(lmp[l].upper_bound(r)!=lmp[l].end()&&rmp[r].lower_bound(l)!=rmp[r].begin()){
            cout<<"2\n";
        }
        else{
            cout<<"-1\n";
        }
    }
}