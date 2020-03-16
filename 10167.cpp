#include<bits/stdc++.h>
using namespace std;

#define all(X) (X).begin(),(X).end()

vector<int> xidx;
vector<int> yidx;

int n;
int ax[3010],ay[3010];



int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	xidx.resize(n);
	yidx.resize(n);
	for(int i=0;i<n;i++){
		cin>>ax[i]>>ay[i];
		xidx[i]=ax[i];
		yidx[i]=ay[i];
	}
	sort(all(xidx));xidx.erase(unique(all(xidx)),xidx.end());
	sort(all(yidx));yidx.erase(unique(all(yidx)),yidx.end());
	for(int i=0;i<n;i++){
		ax[i]=lower_bound(all(xidx),ax[i])-xidx.begin();
		ay[i]=lower_bound(all(yidx),ay[i])-yidx.begin();
	}
}
