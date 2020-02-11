#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

int v[100][2][2][2][2];
int n;
int cnt=0;
int l=-1;
void f(int idx){
	if(idx==16*n){
		++cnt;
		if(cnt>930336768)cout<<"Over!\n";
		return;
	}
	int e=idx/1%2,d=idx/2%2,c=idx/4%2,b=idx/8%2,a=idx/16;
	if(v[a][b][c][d][e]){
		f(idx+1);
		return;
	}
	if(a<n-1&&v[a+1][b][c][d][e]==0){
		v[a][b][c][d][e]=v[a+1][b][c][d][e]=1;
		f(idx+1);
		v[a][b][c][d][e]=v[a+1][b][c][d][e]=0;
	}
	if(b<1&&v[a][b+1][c][d][e]==0){
		v[a][b][c][d][e]=v[a][b+1][c][d][e]=1;
		f(idx+1);
		v[a][b][c][d][e]=v[a][b+1][c][d][e]=0;
	}
	if(c<1&&v[a][b][c+1][d][e]==0){
		v[a][b][c][d][e]=v[a][b][c+1][d][e]=1;
		f(idx+1);
		v[a][b][c][d][e]=v[a][b][c+1][d][e]=0;
	}
	if(d<1&&v[a][b][c][d+1][e]==0){
		v[a][b][c][d][e]=v[a][b][c][d+1][e]=1;
		f(idx+1);
		v[a][b][c][d][e]=v[a][b][c][d+1][e]=0;
	}
	if(e<1&&v[a][b][c][d][e+1]==0){
		v[a][b][c][d][e]=v[a][b][c][d][e+1]=1;
		f(idx+1);
		v[a][b][c][d][e]=v[a][b][c][d][e+1]=0;
	}
}

int main(void){
	cin>>n;
	f(0);
	cout<<cnt;
}
