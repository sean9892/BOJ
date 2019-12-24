#include<bits/stdc++.h>
using namespace std;

multiset<int> s;
int main(void){
	int n;
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x){
			s.insert(x);
		}
		else{
			if(s.empty()){
				cout<<"0\n";
			}
			else{
				cout<<*s.begin()<<"\n";
				s.erase(s.begin());
			}
		}
	}
}
