#include<bits/stdc++.h>
using namespace std;

void TC(){
	string arr[3];
	cin>>arr[0]>>arr[1]>>arr[2];
	int st=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(arr[i][j]=='*')st|=1<<(i*3+j);
		}
	}
	queue<int> q;
	q.push(st);q.push(0);q.push(0);
	while(!q.empty()){
		int s=q.front();q.pop();
		int d=q.front();q.pop();
		int v=q.front();q.pop();
		if(!s){
			cout<<d<<"\n";
			return;
		}
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(v&(1<<(i*3+j)))continue;
				int ns=s;
				if(i>0)ns^=1<<(i*3-3+j);
				if(j>0)ns^=1<<(i*3+j-1);
				if(i<2)ns^=1<<(i*3+3+j);
				if(j<2)ns^=1<<(i*3+j+1);
				ns^=1<<(i*3+j);
				q.push(ns);
				q.push(d+1);
				q.push(v|(1<<(i*3+j)));
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
