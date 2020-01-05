#include<bits/stdc++.h>
using namespace std;

int arr[1000010];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	s="#"+s;
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(s[i]=='I'){
			if(s[i-1]=='O'){
				arr[i]=arr[i-1]+1;
				if(arr[i]>2*n){
					cnt++;
				}
			}
			else arr[i]=1;
		}
		if(s[i]=='O'){
			if(s[i-1]=='I')arr[i]=arr[i-1]+1;
			else arr[i]=0;
		}
	}
	cout<<cnt;
}
