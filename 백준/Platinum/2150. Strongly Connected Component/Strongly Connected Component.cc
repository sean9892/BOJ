#include<bits/stdc++.h>
using namespace std;

const int nmax = 10010;

int v,e,cnt;
int ord[nmax];
int sn;
int grp[nmax];
vector<int> adj[nmax];
int fin[nmax];
stack<int> st;
vector<vector<int>> scc;

int dfs(int now){
    ord[now]=++cnt;
    st.push(now);

    int r=ord[now];
    for(int i:adj[now]){
        if(!ord[i])r=min(r,dfs(i));
        else if(!fin[i])r=min(r,ord[i]);
    }

    if(r==ord[now]){
        vector<int> vec;
        while(1){
            int t=st.top();st.pop();
            vec.push_back(t);
            fin[t]=1;grp[t]=sn;
            if(t==now)break;
        }
        sort(vec.begin(),vec.end());
        scc.push_back(vec);
        sn++;
    }
    return r;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>v>>e;
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    for(int i=1;i<=v;i++)if(!ord[i])dfs(i);
    sort(scc.begin(),scc.end());
    cout<<sn<<"\n";
    for(auto i:scc){
        for(auto j:i)cout<<j<<" ";
        cout<<"-1\n";
    }
}
