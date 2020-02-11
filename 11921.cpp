#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

char buf[1<<22];
int p=0;

char readAll(){
	fread(buf,1,1<<22,stdin);
}

void readint(int& x){
	int r=0;
	x=buf[p++]&15;
	while((r=buf[p++])!='\n')x=x*10+(r&15);
	printf("%d\n",x);
}

int main(void){
	readAll();
	long long s=0;
	int n;
	readint(n);
	while(n--){
		int x;
		readint(x);
		s+=x;
	}
	printf("%lld",s);
}
