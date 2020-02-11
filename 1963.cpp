#include<bits/stdc++.h>
using namespace std;

set<int> v;

int isp(int x){
	for(int i=2;i*i<=x;i++)if(x%i==0)return 0;
	return 1;
}

int vis[10000];
void TC(){
	memset(vis,0,sizeof(vis));
	int a,b;
	cin>>a>>b;
	queue<int> q;
	q.push(a);q.push(0);
	vis[a]=1;
	while(!q.empty()){
		int t=q.front();q.pop();
		int d=q.front();q.pop();
		if(t==b){
			cout<<d<<"\n";
			return;
		}
		for(int i=0,p=1;i<4;i++,p*=10){
			int x=t/p%10;
			for(int j=1-(i!=3);j<10;j++)if(x!=j){
				int k=t-p*x+p*j;
				if(v.find(k)!=v.end()&&!vis[k]){
					vis[k]=1;
					q.push(k);
					q.push(d+1);
				}
			}
		}
	}
	cout<<"Impossible\n";
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	for(int i=1000;i<10000;i++)if(isp(i))v.insert(i);
	int tc;
	cin>>tc;
	while(tc--){
		TC();
	}
}
