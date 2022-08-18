#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
#define fi first
#define se second

int n,m;
vector<int> g[1010];
int cnt[1010];
vector<int> res;
int used[1010];

int main(void){
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  int p=-1;
  int x=0;
  for(int i=1;i<=n;i++){
    x^=i;
  }
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
    cnt[a]++;
    cnt[b]++;
    if(cnt[a]>=n-2)p=a;
    if(cnt[b]>=n-2)p=b;
  }
  assert(p!=-1);
  sort(g[p].begin(),g[p].end());
  for(int i:g[p]){
    x^=i;
  }
  x^=p;
  cout<<"0\n";
  for(int i=1;i<=n;i++){
    cout<<p<<" ";
    used[p]=1;
    int a=-1,b=-1,c=-1;
    for(int j:g[p]){
      if(used[j])continue;
      c=j;
      if(cnt[j]==2){
        a=j;
      }
      if(j==x){
        b=j;
      }
    }
    for(int j:g[p]){
      cnt[j]--;
    }
    if(a!=-1){
      p=a;
    }
    else if(b!=-1){
      p=b;
    }
    else{
      p=c;
    }
  }
}