#include<bits/stdc++.h>
using namespace std;
using uint=unsigned int;

struct node{
	int cnt;
	int l,r;
};
vector<node> v;

void add(uint x){
	int p=0;
	for(int i=30;i>=0;i--){
		++v[p].cnt;
		if(x&(1<<i)){
			if(v[p].r==-1){
				v[p].r=v.size();
				v.push_back({0,-1,-1});
			}
			p=v[p].r;
		}
		else{
			if(v[p].l==-1){
				v[p].l=v.size();
				v.push_back({0,-1,-1});
			}
			p=v[p].l;
		}
	}
	++v[p].cnt;
}

void del(uint x){
	int p=0;
	for(int i=30;i>=0;i--){
		--v[p].cnt;
		if(x&(1<<i)){
			if(v[p].r==-1){
				v[p].r=v.size();
				v.push_back({0,-1,-1});
			}
			p=v[p].r;
		}
		else{
			if(v[p].l==-1){
				v[p].l=v.size();
				v.push_back({0,-1,-1});
			}
			p=v[p].l;
		}
	}
	--v[p].cnt;
}

uint query(uint x){
	int p=0;
	uint r=0;
	for(int i=30;i>=0;i--){
		if(v[p].l==-1&&v[p].r==-1)return r;
		if((x&(1<<i))){
			if(v[p].l!=-1){
				p=v[p].l;
				if(v[v[p].l].cnt)r|=(1<<i);
			}
			else p=v[p].r;
		}
		else{
			if(v[p].r!=-1){
				p=v[p].r;
				if(v[v[p].r].cnt)r|=(1<<i);
			}
			else p=v[p].l;
		}
	}
	return r;
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int q;
	cin>>q;
	v.push_back({0,-1,-1});
	for(int i=0;i<q;i++){
		int t;
		uint x;
		cin>>t>>x;
		if(t==1){
			add(x);
		}
		if(t==2){
			del(x);
		}
		if(t==3){
			cout<<query(x)<<"\n";
		}
	}
}
