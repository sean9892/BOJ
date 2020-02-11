#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

vector<int> idx;
int qv[100010][2];
int seg[800010];
int lazy[800010];

void prop(int idx,int l,int r){
	if(lazy[idx]==-1)return;
	seg[idx]=lazy[idx];
	if(l!=r){
		int le=idx<<1,ri=le|1;
		lazy[le]=lazy[ri]=lazy[idx];
	}
	lazy[idx]=-1;
}

void upd(int idx,int l,int r,int s,int e,int v){
	prop(idx,l,r);
	if(l>e||r<s)return;
	if(s<=l&&r<=e){
		lazy[idx]=v;
		prop(idx,l,r);
		return;
	}
	int m=l+r>>1;
	int le=idx<<1,ri=le|1;
	upd(le,l,m,s,e,v);upd(ri,m+1,r,s,e,v);
	seg[idx]=max(seg[le],seg[ri]);
}

int query(int idx,int l,int r,int s,int e){
	prop(idx,l,r);
	if(l>e||r<s)return 0;
	if(s<=l&&r<=e)return seg[idx];
	int m=l+r>>1;
	int le=idx<<1,ri=le|1;
	return max(query(le,l,m,s,e),query(ri,m+1,r,s,e));
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	memset(lazy,0,sizeof(lazy));
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>qv[i][0]>>qv[i][1];
		swap(qv[i][0],qv[i][1]);
		qv[i][1]+=qv[i][0]-1;
		idx.push_back(qv[i][0]);
		idx.push_back(qv[i][1]);
	}
	sort(idx.begin(),idx.end());
	idx.erase(unique(idx.begin(),idx.end()),idx.end());
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++)qv[i][j]=lower_bound(idx.begin(),idx.end(),qv[i][j])-idx.begin()+1;
	}
	for(int i=0;i<n;i++){
		int mx=query(1,1,200010,qv[i][0],qv[i][1]);
		upd(1,1,200010,qv[i][0],qv[i][1],mx+1);
	}
	cout<<query(1,1,200010,1,200010);
}
