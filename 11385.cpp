#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;

using cpx=complex<long double>;
const double pi=acos(-1);

void fft(vector<cpx> &v,cpx w){
	int n=v.size();
	if(n==1)return;
	vector<cpx> even(n/2),odd(n/2);
	for(int i=0;i<n;i++){
		if(i&1)odd[i/2]=v[i];
		else even[i/2]=v[i];
	}
	fft(even,w*w);fft(odd,w*w);
	cpx wp(1,0);
	for(int i=0;i<n/2;i++){
		v[i]=even[i]+wp*odd[i];
		v[i+n/2]=even[i]-wp*odd[i];
		wp*=w;
	}
}

vector<cpx> mult(vector<cpx> a,vector<cpx> b){
	int n=1;
	while(n<=a.size()||n<=b.size())n<<=1;n<<=1;
	a.resize(n);b.resize(n);
	vector<cpx> c(n);
	cpx w(cos(2*pi/n),sin(2*pi/n));
	fft(a,w);fft(b,w);
	for(int i=0;i<n;i++)c[i]=a[i]*b[i];
	fft(c,cpx(1,0)/w);
	for(int i=0;i<n;i++){
		c[i]/=cpx(n,0);
		c[i]=cpx(round(c[i].real()),round(c[i].imag()));
	}
	return c;
}

int32_t main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<cpx> a(n+1),b(m+1);
	for(int i=0;i<=n;i++){
		ull x;cin>>x;
		a[i]=cpx(x,0);
	}
	for(int i=0;i<=m;i++){
		ull x;cin>>x;
		b[i]=cpx(x,0);
	}
	vector<cpx> r(mult(a,b));
	ull res=0;
	for(auto i:r){
		res^=(ull)round(i.real());
	}
	cout<<res;
}
