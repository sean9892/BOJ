#include<bits/stdc++.h>
using namespace std;

int c[2010];

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		c[x+1000]=1;
	}
	for(int i=0;i<2001;i++)if(c[i])cout<<i-1000<<" ";
}
