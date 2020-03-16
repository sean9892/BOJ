#include<bits/stdc++.h>
using namespace std;

#define sz(x) x.size()
#define frt(x) x.front()
#define bck(x) x.back()

#define NMAX 100010
#define VMAX 100010
#define QMAX 100010

int n,k,m,sq;
int arr[NMAX];
list<int> exi[VMAX];
int cnt[NMAX];
int sqd[400];
int op[QMAX];

struct Query{
	int idx,s,e;
	bool operator<(Query& t){
		if(s/sq^t.s/sq)return s/sq<t.s/sq;
		return e<t.e;
	}
};

vector<Query> qv;

void add(int x){
	if(sz(exi[arr[x]])>=2){
		int d=bck(exi[arr[x]])-frt(exi[arr[x]]);
		--cnt[d];--sqd[d/sq];
	}
	if(exi[arr[x]].empty()||bck(exi[arr[x]])<x){
		exi[arr[x]].push_back(x);
	}
	else{
		exi[arr[x]].push_front(x);
	}
	if(sz(exi[arr[x]])>=2){
		int d=bck(exi[arr[x]])-frt(exi[arr[x]]);
		++cnt[d];++sqd[d/sq];
	}
}

void erase(int x){
	if(sz(exi[arr[x]])>=2){
		int d=bck(exi[arr[x]])-frt(exi[arr[x]]);
		--cnt[d];--sqd[d/sq];
	}
	if(bck(exi[arr[x]])==x){
		exi[arr[x]].pop_back();
	}
	else{
		exi[arr[x]].pop_front();
	}
	if(sz(exi[arr[x]])>=2){
		int d=bck(exi[arr[x]])-frt(exi[arr[x]]);
		++cnt[d];++sqd[d/sq];
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>k;
	n++;
	for(int i=2;i<=n;i++){
		cin>>arr[i];
		arr[i]%=k;
		arr[i]+=arr[i-1];
		arr[i]%=k;
	}
	
	for(sq=0;sq*sq<=n;sq++);
	cin>>m;
	qv.resize(m);
	for(int i=0;i<m;i++){
		qv[i].idx=i;
		cin>>qv[i].s>>qv[i].e;
		qv[i].s++;qv[i].e++;
	}
	sort(qv.begin(),qv.end());
	
	int l=1,r=1;
	cnt[0]=sqd[0]=k+3;
	add(1);
	for(int i=0;i<m;i++){
		int s=qv[i].s,e=qv[i].e;
		while(l+1>s){
			add(--l);
		}
		while(r<e){
			add(++r);
		}
		while(l+1<s){
			erase(l++);
		}
		while(r>e){
			erase(r--);
		}
		int p=(n+1)/sq;
		while(!sqd[p])p--;
		int q=min(n,(p+1)*sq);
		while(!cnt[q])q--;
		op[qv[i].idx]=q;
	}
	for(int i=0;i<m;i++){
		cout<<op[i]<<"\n";
	}
}
