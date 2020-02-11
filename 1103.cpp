#include<bits/stdc++.h>
using namespace std;

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

int n,m;
int arr[50][50];
int vis[50][50];
int dp[50][50];

int vpos(int x,int y){
	return x>=0&&x<n&&y>=0&&y<m;
}

int solve(int x,int y){
	if(!vpos(x,y)||arr[x][y]==-1)return 0;
	if(dp[x][y])return dp[x][y];
	vis[x][y]=1;
	int r=0;
	for(int i=0;i<4;i++){
		int nx=dx[i]*arr[x][y]+x;
		int ny=dy[i]*arr[x][y]+y;
		if(vpos(nx,ny)&&vis[nx][ny]){
			puts("-1");
			exit(0);
		}
		r=max(r,solve(nx,ny));
	}
	vis[x][y]=0;
	return dp[x][y]=r+1;
}

int main(void){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf(" %c",&arr[i][j]);
			if(arr[i][j]!='H')arr[i][j]-='0';
			else arr[i][j]=-1;
		}
	}
	printf("%d",solve(0,0));
}
