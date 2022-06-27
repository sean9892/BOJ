#include<bits/stdc++.h>
using namespace std;

int le[300010];
int ri[300010];
long long a[300010];
int ex[300010];

void pop(int idx){
    ex[idx]=0;
    int l=le[idx],r=ri[idx];
    ri[l]=r;
    le[r]=l;
}

string s;
int32_t main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    cin>>s;
    if(n<=2){
        cout<<"0";
        return 0;
    }
    s="_"+s;
    a[0]=-0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ex[i]=1;
        le[i]=i-1;
        ri[i]=i+1;
    }
    a[n+1]=-0x3f3f3f3f;
    for(int i=2;i<=n;i++){
        if(s[le[i]]==s[i]){
            if(a[le[i]]<a[i]){
                pop(le[i]);
            }
            else{
                pop(i);
            }
        }
    }
    priority_queue<int> q;
    for(int i=1;i<=n;i++){
        if(ex[i]&&le[i]!=0&&ri[i]!=n+1){
            q.push(a[i]);
        }
    }
    int m = q.size();
    long long res=0;
    for(int i=0;i<(m+1)/2;i++){
        res+=q.top();q.pop();
    }
    cout<<res;
}