#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
#define fi first
#define se second

int N,D,C;
vector<pii> g[10010];
int dist[10010];

void TC(){
  memset(dist,0x3f,sizeof(dist));
  for(int i=1;i<=10000;i++){
    g[i]=vector<pii>();
  }
  cin>>N>>D>>C;
  for(int i=0;i<D;i++){
    int a,b,s;
    cin>>a>>b>>s;
    g[b].emplace_back(a,s);
  }
  priority_queue<pii> q;
  q.push(pii(~0,C));
  dist[C]=0;
  while(!q.empty()){
    int d,t;
    tie(d,t)=q.top();q.pop();
    d=~d;
    if(dist[t]<d)continue;
    for(auto &k:g[t]){
      int i,s;
      tie(i,s)=k;
      if(d+s<dist[i]){
        dist[i]=d+s;
        q.push(pii(~dist[i],i));
      }
    }
  }
  int cnt=0,mx=0;
  for(int i=1;i<=N;i++){
    if(dist[i]<0x3f3f3f3f){
      cnt++;
      mx=max(mx,dist[i]);
    }
  }
  cout<<cnt<<" "<<mx<<"\n";
}

int main(void){
  ios::sync_with_stdio(0);cin.tie(0);
  int tc;
  cin>>tc;
  while(tc--)TC();
}