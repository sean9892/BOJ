#include<bits/stdc++.h>
using namespace std;

int main(void){
	int sum=0;
	int mx=987654321;
	for(int i=0;i<7;i++){
		int x;
		cin>>x;
		if(x&1){
			sum+=x;
			mx=min(mx,x);
		}
	}
	if(sum>0)cout<<sum<<"\n"<<mx;
	else cout<<"-1";
}
