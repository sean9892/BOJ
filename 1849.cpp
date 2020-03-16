#include<bits/stdc++.h>
using namespace std;

int n;
int res[100010];
int inv[100010];
int seg[100010<<2];

void upd(int idx,int l,int r,int p,int x){
	if(l>p||r<p)return;
	if(l==r){
		seg[idx]=x;
		return;
	}
	int m=l+r>>1,le=idx<<1,ri=le|1;
	upd(le,l,m,p,x);upd(ri,m+1,r,p,x);
	seg[idx]=seg[le]+seg[ri];
}

int query(int idx,int l,int r,int s,int e){
	if(l>e||r<s)return 0;
	if(s<=l&&r<=e)return seg[idx];
	int m=l+r>>1,le=idx<<1,ri=le|1;
	return query(le,l,m,s,e)+query(ri,m+1,r,s,e);
}

int fnd(int v){
	int l=1,r=n;
	while(l<=r){
		int m=l+r>>1;
		int x;
		if(m==n){
			x=0;
		}
		else{
			x=query(1,1,n,m+1,n);
		}
		if(x>v){
			l=m+1;
		}
		if(x==v){
			if(res[m]){
				r=m-1;
			}
			else{
				return m;
			}
		}
		if(x<v){
			r=m-1;
		}
	}
	return -1;
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>inv[i];
		upd(1,1,n,i,1);
	}
	for(int i=1;i<=n;i++){
		int x=fnd(inv[i]);
		res[x]=i;
		upd(1,1,n,x,0);
	}
	for(int i=n;i>0;i--){
		cout<<res[i]<<" ";
	}
}
