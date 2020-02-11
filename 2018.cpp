#include<bits/stdc++.h>
using namespace std;

int main(void){
	int n;
	cin>>n;
	int cnt=0;
	for(int i=1;2*n-i*i+i>0;i++)if((2*n-i*i+i)%(2*i)==0)cnt++;
	cout<<cnt;
}
