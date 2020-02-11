#include<bits/stdc++.h>
using namespace std;

const int nmax=500010;
vector<int> idx;
int v[nmax];
int seg[nmax<<2];

int getidx(int x){
	return lower_bound(idx.begin(),idx.end(),x)-idx.begin();
}

void upd(int idx,int l,int r,int p,int v){
	if(l>p||r<p)return;
	if(l!=r){
		int m=l+r>>1,le=idx<<1,ri=le|1;
		upd(le,l,m,p,v);upd(ri,m+1,r,p,v);
		seg[idx]=seg[le]+seg[ri];
		return;
	}
	seg[idx]=v;
}

int query(int idx,int l,int r,int s,int e){
	if(l>e||r<s)return 0;
	if(s<=l&&r<=e)return seg[idx];
	int m=l+r>>1,le=idx<<1,ri=le|1;
	return query(le,l,m,s,e)+query(ri,m+1,r,s,e);
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>v[i];
		idx.push_back(v[i]);
	}
	sort(idx.begin(),idx.end());
	idx.erase(unique(idx.begin(),idx.end()),idx.end());
	for(int i=0;i<n;i++){
		int g=getidx(v[i]);
		int q=query(1,0,n-1,g,n-1);
		cout<<q+1<<"\n";
		upd(1,0,n-1,g,1);
	}
}
