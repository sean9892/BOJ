#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
#define get(v,x) ((((v)[x/64]>>(x&63))&1)==1)
#define set(v,x) ((v)[x/64]|=1llu<<(x&63))

int f(ll &x,ll y){
	ll t=x;
	x=t-y;
	return x>t;
}

int mx=0;
int l;

void lcs(string a,string b){
	int n=a.size(),m=b.size();
	int sz=m/64+1;
	vector<ll> s[256],row(sz);
	for(int i=0;i<256;i++)s[i].resize(sz);
	for(int i=0;i<m;i++)set(s[b[i]],i);
	for(int i=0;i<m;i++)if(a[0]==b[i]){
		set(row,i);break;
	}
	for(int i=1;i<n;i++){
		ll aa=1,bb=0;
		for(int j=0;j<sz;j++){
			ll x=s[a[i]][j]|row[j];
			ll q=(row[j]<<1)|aa,w=x;
			aa=row[j]>>63;
			bb=f(w,bb);bb+=f(w,q);
			row[j]=x&(x^w);
		}
		row[m/64]&=(1llu<<(m&63))-1;
	}
	int r=0;
	for(int i=0;i<m;i++)if(get(row,i)){
		r++;
	}
	if(mx<r){
		mx=r;
		l=a.size();
	}
}

int dp[3010][3010];

int ntc=0;
void TC(){
	string s;
	cin>>s;
	mx=l=0;
	const int ss=s.size();
	lcs(s.substr(0,ss/2),s.substr(ss/2,ss-ss/2));
	for(int i=1;i<=ss;i++){
		if(i<=mx||ss-i<=mx)continue;
		string res;
		lcs(s.substr(0,i),s.substr(i,ss-i));
	}
	++ntc;
	cout<<"Case #"<<ntc<<": "<<mx*2<<"\n";
	if(mx!=0){
		string a="|"+s.substr(0,l),b="|"+s.substr(l,ss-l);
		for(int i=1;i<=l;i++){
			for(int j=1;j<=ss-l;j++){
				if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		stack<char> st;
		int p=l,q=ss-l;
		while(p&&q){
			if(dp[p][q]==dp[p][q-1])q--;
			else if(dp[p][q]==dp[p-1][q])p--;
			else{
				st.push(a[p]);
				p--;q--;
			}
		}
		string r="";
		while(!st.empty()){
			r=r+st.top();st.pop();
		}
		cout<<r<<r<<"\n";
	}
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
		TC();
	}
}