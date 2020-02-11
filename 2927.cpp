#include<bits/stdc++.h>
using namespace std;

/***
Disjoint Set (Union-Find)
p[x]: parent of x (p[root node] = size of disjoint set) 
fnd(u): find root node (with path compression)
mer(u,v): union u and v (root will be u)
***/
struct UF{
	vector<int> p;
	int fnd(int u){
		return p[u]<0?u:(p[u]=fnd(p[u]));
	}
	int mer(int u,int v){
		u=fnd(u);v=fnd(v);
		if(u==v)return 0;
		p[u]+=p[v];
		p[v]=u;
		return 1;
	}
};

int main(void){
	
}
