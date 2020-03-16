#include<bits/stdc++.h>
using namespace std;

const int nmax=1510;
const int bias=1<<11;
int n,m;
int arr[nmax][nmax];
int seg[bias<<1][bias<<1];

void init(){
	for(int i=0;i<=1500;i++)
		for(int j=0;j<=1500;j++)
			seg[bias|i][bias|j]=arr[i][j];
	for(int i=0;i<=1500;i++){
		for(int j=bias-1;j;j--){
			seg[bias|i][j]=max(seg[bias|i][j<<1],seg[bias|i][j<<1|1]);
		}
	}
	for(int i=bias-1;i;i--){
		for(int j=bias*2-1;j;j--){
			seg[i][j]=max(seg[i<<1][j],seg[i<<1|1][j]);
		}
	}
}

int q1(int idx,int l,int r){
	int res=0;
	for(l|=bias,r|=bias;l<=r;l>>=1,r>>=1){
		if(l&1)res=max(res,seg[idx][l++]);
		if(!(r&1))res=max(res,seg[idx][r--]);
	}
	return res;
}

int q2(int x1,int x2,int y1,int y2){
	int res=0;
	for(x1|=bias,x2|=bias;x1<=x2;x1>>=1,x2>>=1){
		if(x1&1)res=max(res,q1(x1++,y1,y2));
		if(!(x2&1))res=max(res,q1(x2--,y1,y2));
	}
	return res;
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		arr[a][b]++;arr[c][d]++;
		arr[a][d]--;arr[c][b]--;
	}
	for(int i=0;i<=1500;i++){
		for(int j=0;j<=1500;j++){
			if(i)arr[i][j]+=arr[i-1][j];
			if(j)arr[i][j]+=arr[i][j-1];
			if(i&&j)arr[i][j]-=arr[i-1][j-1];
		}
	}
	init();
	for(int i=0;i<m;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		cout<<q2(a,c-1,b,d-1)<<"\n";
	}
}
