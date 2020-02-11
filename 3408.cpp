#include<bits/stdc++.h>
using namespace std;

const int nmax = 2e5+10;

int n;
int a[nmax];
int l[nmax];
int v[nmax];
int prv[nmax],nxt[nmax];

int f(int l,int r){
	if(l>=r)return 0;
	for(int i=0;i<r-l+1;i++){
		int p;
		if(i&1)p=l+i/2;
		else p=r-i/2;
		if(prv[p]<l&&r<nxt[p])return f(l,p-1)||f(p+1,r);
	}
	return 1;
}

void TC(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		v[i]=a[i];
	}
	sort(v,v+n);
	int vc=unique(v,v+n)-v;
	for(int i=0;i<n;i++)a[i]=lower_bound(v,v+vc,a[i])-v;
	
	//Set a[i]'s previous index (not exist -> prv[i]=-1
	for(int i=0;i<n;i++)l[a[i]]=-1;
	for(int i=0;i<n;i++){
		prv[i]=l[a[i]];
		l[a[i]]=i;
	}
	//Set a[i]'s next index (not exist -> nxt[i]=n
	for(int i=0;i<n;i++)l[a[i]]=n;
	for(int i=n-1;i>=0;i--){
		nxt[i]=l[a[i]];
		l[a[i]]=i;
	}
	
	cout<<(f(0,n-1)?"boring\n":"non-boring\n");
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
		TC();
	}
}
