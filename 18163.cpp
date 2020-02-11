#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using mat=vector<vector<int>>;

int n;

void mult(const mat a,const mat& b,mat& r){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			r[i][j]=0;
			for(int k=0;k<n;k++){
				r[i][j]^=a[i][k]&b[k][j];
			}
		}
	}
}

int bmul(int x,int y){
	int r=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				r^=((x&(1<<(i*n+k)))&&(y&(1<<(k*n+j))))<<(i*n+j);
			}
		}
	}
	return r;
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	if(n==4){
		vector<int> v(1);
		for(int i=0;i<n*n;i++){
			int x;cin>>x;
			v[0]|=(x<<i);
		}
		for(int i=1;;i++){
			v.push_back(bmul(v[i-1],v[0]));
			for(int j=i-1;j>=0;j--){
				if(v[i]==v[j]){
					cout<<i+1;
					return 0;
				}
			}
		}
		return 0;
	}
	mat ini(n,vector<int>(n));
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>ini[i][j];
	mat x(n,vector<int>(n));
	mult(ini,ini,x);
	int c=2;
	while(ini!=x){
		c++;
		mult(x,ini,x);
	}
	cout<<c;
}
