#include<bits/stdc++.h>
using namespace std;

int main(void){
	long long n,x;
	cin>>n;
	for(x=1;x*x<=n;x++);
	cout<<x-1;
}
