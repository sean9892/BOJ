#include<bits/stdc++.h>
using namespace std;
using ll=long long;

struct rat{
    ll top,bot;
    rat(ll x,ll y=1):top(x),bot(y){}
    bool operator==(const rat t){
        return top==t.top&&bot==t.bot;
    }
};

ll gcd(ll a,ll b){
    a=abs(a);b=abs(b);
    if(a<b)swap(a,b);
    if(!b)return a;
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}

rat reduction(rat x){
    ll g=gcd(abs(x.top),abs(x.bot));
    return rat(x.top/g,x.bot/g);
}

rat add(rat a,rat b){
    ll g=lcm(a.bot,b.bot);
    return reduction(rat(a.top*g/a.bot+b.top*g/b.bot,g));
}

rat mult(rat a,rat b){
    return reduction(rat(a.top*b.top,a.bot*b.bot));
}

int n;
vector<int> v;
#define pr(x) x.top<<"/"<<x.bot
void tc(){
    cin>>n;
    v.clear();
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    if(n<5){
        cout<<"YES\n";
        return;
    }
    const rat A=rat(v[0]);
    const rat B=rat(v[1]);
    const rat C=rat(v[2]);
    const rat D=rat(v[3]);
    const rat mns=rat(-1);
    const rat a=add(mult(rat(1,2),add(B,mult(mns,C))),mult(rat(1,6),add(D,mult(mns,A))));
    const rat b=add(mult(mns,add(D,mult(rat(4),B))),mult(rat(1,2),add(mult(rat(7),C),mult(rat(3),A))));
    const rat c=add(add(mult(rat(-13,3),A),mult(rat(19,2),B)),add(mult(rat(-7),C),mult(rat(11,6),D)));
    const rat d=add(mult(rat(4),add(A,C)),add(mult(rat(-6),B),mult(mns,D)));
    for(ll i=5;i<=n;i++){
        bool x=(add(add(mult(a,rat(i*i*i)),mult(b,rat(i*i))),add(mult(c,rat(i)),d))==rat(v[i-1]));
        rat r=add(add(mult(a,rat(i*i*i)),mult(b,rat(i*i))),add(mult(c,rat(i)),d));
        if(!x){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    int TC;
    cin>>TC;
    while(TC--){
        tc();
    }
}
