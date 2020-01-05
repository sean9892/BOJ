#include<bits/stdc++.h>
using namespace std;

int n;
int arr[110][110];
int a[110][110];
int b[110][110];

bool vpos(int x,int y){
	return 0<=x&&x<n&&0<=y&&y<n;
}

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

void dfs1(int x,int y,int c){
	if(!vpos(x,y)||arr[x][y]!=c||a[x][y])return;
	a[x][y]=1;
	for(int i=0;i<4;i++){
		dfs1(x+dx[i],y+dy[i],c);
	}
}

void dfs2(int x,int y,int c){
	if(!vpos(x,y)||!!arr[x][y]!=!!c||b[x][y])return;
	b[x][y]=1;
	for(int i=0;i<4;i++){
		dfs2(x+dx[i],y+dy[i],c);
	}
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<n;j++){
			if(s[j]=='R')arr[i][j]=1;
			if(s[j]=='G')arr[i][j]=2;
			if(s[j]=='B')arr[i][j]=0;
		}
	}
	int e=0,r=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!a[i][j]){
				e++;
				dfs1(i,j,arr[i][j]);
			}
			if(!b[i][j]){
				r++;
				dfs2(i,j,arr[i][j]);
			}
		}
	}
	cout<<e<<" "<<r;
}
