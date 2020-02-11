#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=1e9+7;

int n=60;

ll mem[211][2<<16];

ll f(int,int);
ll g(int,int,int,int);

ll f(int idx,int st){
	if(idx==n)return !st;
	if(~mem[idx][st])return mem[idx][st];
	return mem[idx][st]=g(idx,0,st,0);
}

ll g(int idx,int p,int st,int nst){
	if(p==16)return f(idx+1,nst);
	if(st&(1<<p))return g(idx,p+1,st,nst);
	ll r=0;
	for(int i=0;i<4;i++){
		if(st&(1<<(p+(1<<i))))continue;
		if(p&(1<<i))continue;
		r+=g(idx,p+1,st|(1<<(p+(1<<i))),nst);
		r%=mod;
	}
	r+=g(idx,p+1,st,nst|(1<<p));
	r%=mod;
	return r;
}

int main(void){
	memset(mem,-1,sizeof(mem));
	ofstream of("output.txt",ios_base::out|ios_base::app);
	ll res=f(0,0);
	cout<<res<<",";
	of<<res<<",";
	of.close();
	n++;
	if(n<200)main();
	return 0;
}
