#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
#define fi first
#define se second

int le[100010],ri[100010];
int dist[100010];
int v[100010];
int N,K;

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>N>>K;
    int x;
    cin>>x;
    ri[1]=2;
    le[N+1]=N;
    dist[1]=1e9;
    dist[N+1]=1e9;
    priority_queue<pii,vector<pii>,greater<pii> > q;
    q.push(pii(1e9,1));
    q.push(pii(1e9,N+1));
    for(int i=2;i<=N;i++){
        int y;
        cin>>y;dist[i]=y-x;
        q.push(pii(y-x,i));
        le[i]=i-1;
        ri[i]=i+1;
        x=y;
    }
    int res=0;
    while(K--){
        while(v[q.top().se])q.pop();
        int d,i;
        tie(d,i)=q.top();
        q.pop();
        res+=d;
        dist[i]=dist[le[i]]+dist[ri[i]]-dist[i];
        q.push(pii(dist[i],i));
        v[le[i]]=v[ri[i]]=1;
        le[i]=le[le[i]];
        ri[i]=ri[ri[i]];
        ri[le[i]]=i;
        le[ri[i]]=i;
    }
    cout<<res;
}