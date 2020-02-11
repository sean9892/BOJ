#include<bits/stdc++.h>
using namespace std;

int main(void){
	long long n;
	cin>>n;
	if(!n){
		cout<<0;
		return 0;
	}
	stack<long long> r;
	while(n!=1){
		if(n>0){
			r.push(n%2);
			n/=-2;
		}
		else{
			if((-n)%2==0){
				n/=-2;
				r.push(0);
			}
			else{
				n=(-n)/2+1;
				r.push(1);
			}
		}
	}
	cout<<1;
	while(!r.empty()){
		cout<<r.top();
		r.pop();
	}
}
