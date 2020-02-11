#include<bits/stdc++.h>
using namespace std;

int l;
int vpos(int x,int y){
	return x>=0&&x<l&&y>=0&&y<l;
}

int v[310][310];
const int dx[] = {-2,-1,1,2,-2,-1,1,2};
const int dy[] = {-1,-2,-2,-1,1,2,2,1};
void TC(){
	memset(v,0,sizeof(v));
	cin>>l;
	queue<int> q;
	int a,b;
	cin>>a>>b;
	q.push(a);q.push(b);q.push(0);
	cin>>a>>b;
	while(!q.empty()){
		int x,y,d;
		x=q.front();q.pop();y=q.front();q.pop();d=q.front();q.pop();
		if(x==a&&y==b){
			cout<<d<<"\n";
			return;
		}
		for(int i=0;i<8;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if(vpos(nx,ny)&&!v[nx][ny]){
				q.push(nx);
				q.push(ny);
				q.push(d+1);
				v[nx][ny]=1;
			}
		}
	}
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
		TC();
	}
}
