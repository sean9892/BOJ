#include<bits/stdc++.h>
using namespace std;
#define int long long

const int nmax=1e6+10;
int n,b,c;
int a[3][nmax];

int32_t main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>b>>c;
	for(int i=1;i<=n;i++){
		cin>>a[0][i];
	}
	if(b<=c){
		int sum=0;
		for(int i=1;i<=n;i++)sum+=a[0][i];
		cout<<sum*b;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(i>1){
			if(a[0][i-1]&&a[0][i]){
				int m=min(a[0][i-1],a[0][i]);
				a[0][i-1]-=m;a[0][i]-=m;
				a[1][i]+=m;
			}
		}
		if(i>2){
			if(a[0][i-2]&&a[0][i-1]&&a[0][i]){
				int m=min({a[0][i-2],a[0][i-1],a[0][i]});
				a[0][i-2]-=m;a[0][i-1]-=m;a[0][i]-=m;
				a[2][i]+=m;
			}
			if(a[0][i-2]&&a[1][i]){
				int m=min(a[0][i-2],a[1][i]);
				a[0][i-2]-=m;a[1][i]-=m;
				a[2][i]+=m;
			}
			if(a[1][i-1]&&a[0][i]){
				int m=min(a[1][i-1],a[0][i]);
				a[1][i-1]-=m;a[0][i]-=m;
				a[2][i]+=m;
			}
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[0][i]*b+a[1][i]*(b+c)+a[2][i]*(b+2*c);
	}
	cout<<sum;
}
