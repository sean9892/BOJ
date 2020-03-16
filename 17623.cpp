#include<bits/stdc++.h>
using namespace std;

string s[1010];
int d[256];

bool cmp(string x,string y){
	if(x.size()!=y.size())return x.size()<y.size();
	for(int i=0;i<x.size();i++){
		int a=d[x[i]],b=d[y[i]];
		if(a!=b)return a<b;
	}
	return 0;
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	
	d['(']=1;d[')']=2;
	d['{']=3;d['}']=4;
	d['[']=5;d[']']=6;
	s[1]="()";
	s[2]="{}";
	s[3]="[]";
	for(int i=4;i<=1000;i++){
		s[i]="()"+s[i-1];
		for(int j=2;j<i;j++)if(cmp(s[j]+s[i-j],s[i]))s[i]=s[j]+s[i-j];
		if(i%2==0)if(cmp("("+s[i/2]+")",s[i]))s[i]="("+s[i/2]+")";
		if(i%3==0)if(cmp("{"+s[i/3]+"}",s[i]))s[i]="{"+s[i/3]+"}";
		if(i%5==0)if(cmp("["+s[i/5]+"]",s[i]))s[i]="["+s[i/5]+"]";
	}
	
	int tc;
	cin>>tc;
	while(tc--){
		int n;
		cin>>n;
		cout<<s[n]<<"\n";
	}
}
