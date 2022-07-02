#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
#define x first
#define y second

ll ccw(pll a,pll b,pll c){
    return a.x*b.y-a.y*b.x
          +b.x*c.y-c.x*b.y
          +c.x*a.y-c.y*a.x;
}

int main(void){
    pll a1,a2,b1,b2;
    for(auto t:{&a1,&a2,&b1,&b2}){
        cin>>t->x>>t->y;
    }
    cout<<(int)((ccw(a1,a2,b1)>0)==(ccw(a2,a1,b2)>0)&&(ccw(b1,b2,a1)>0)==(ccw(b2,b1,a2)>0));
}