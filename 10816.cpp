#include<bits/stdc++.h>
using namespace std;

const int v=10000000;
int arr[20000010];

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		++arr[x+v];
	}
	cin>>m;
	while(m--){
		int x;
		cin>>x;
		cout<<arr[x+v]<<" ";
	}
}
