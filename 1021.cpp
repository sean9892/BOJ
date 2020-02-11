#include<bits/stdc++.h>
using namespace std;

int main(void){
	int n,m;
	cin>>n>>m;
	deque<int> q;
	int r=0;
	for(int i=1;i<=n;i++)q.push_back(i);
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		if(q.front()==x)q.pop_front();
		else{
			int idx=0;
			for(int j:q){
				if(j==x)break;
				idx++;
			}
			if(q.size()/2<idx){
				while(q.front()!=x){
					int y=q.back();
					q.pop_back();
					q.push_front(y);
					r++;
				}
				q.pop_front();
			}
			else{
				while(q.front()!=x){
					int y=q.front();
					q.pop_front();
					q.push_back(y);
					r++;
				}
				q.pop_front();
			}
		}
	}
	cout<<r;
}
