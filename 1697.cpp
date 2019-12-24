#include<bits/stdc++.h>
using namespace std;
int v[200000];
#define isr(x) ((x)<200000&&0<=(x))
int main(void){
	int n,k;
	cin>>n>>k;
	queue<int> q;
	q.push(n);
	v[n]=1;
	while(!q.empty()){
		int t=q.front();q.pop();
		if(t==k){
			cout<<v[t]-1;
			return 0;
		}
		if(isr(t-1)&&!v[t-1]){
			q.push(t-1);v[t-1]=v[t]+1;
		}
		if(isr(t+1)&&!v[t+1]){
			q.push(t+1);v[t+1]=v[t]+1;
		}
		if(isr(t*2)&&!v[t*2]){
			q.push(t*2);v[t*2]=v[t]+1;
		}
	}
}
