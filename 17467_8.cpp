//Thx to secmem...
#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned ll;
using cpx=complex<double>;

void fft(vector<cpx> &v,bool inv){
	int n=v.size(),j=0;
	for(int i=1;i<n;i++){
		int bit=(n>>1);
		while(j>=bit){
			j-=bit;
			bit>>=1;
		}
		j+=bit;
		if(i<j)swap(v[i],v[j]);
	}
	double ang=2*acos(-1)/n*(inv?-1:1);
	vector<cpx> rts(n>>1);
	for(int i=0;i<(n>>1);i++)rts[i]=cpx(cos(ang*i),sin(ang*i));
	for(int i=2;i<=n;i<<=1){
		int st=n/i;
		for(int j=0;j<n;j+=i){
			for(int k=0;k<i/2;k++){
				cpx uu=v[j+k],vv=v[j+k+i/2]*rts[st*k];
				v[j+k]=uu+vv;
				v[j+k+i/2]=uu-vv;
			}
		}
	}
	if(inv)for(int i=0;i<n;i++)v[i]/=n;
}

vector<ll> multiply(vector<ll> &v,vector<ll> w,ll mod){
	int n=2;
	while(n<v.size()+w.size())n<<=1;
	vector<cpx> a(n),b(n),x(n),y(n);
	for(int i=0;i<v.size();i++)a[i]=cpx(v[i]>>15,v[i]&32767);
	for(int i=0;i<w.size();i++)b[i]=cpx(w[i]>>15,w[i]&32767);
	fft(a,0);fft(b,0);
	for(int i=0;i<n;i++){
		int j=(i?(n-i):i);
		cpx r1=(a[i]+conj(a[j]))*cpx(0.5,0);
		cpx r2=(a[i]-conj(a[j]))*cpx(0,-0.5);
		cpx r3=(b[i]+conj(b[j]))*cpx(0.5,0);
		cpx r4=(b[i]-conj(b[j]))*cpx(0,-0.5);
		x[i]=r1*r3+r1*r4*cpx(0,1);
		y[i]=r2*r3+r2*r4*cpx(0,1);
	}
	fft(x,1);fft(y,1);
	vector<ll> res(n);
	for(int i=0;i<n;i++){
		ll av=(ll)round(x[i].real());
		ll bv=(ll)round(x[i].imag())+(ll)round(y[i].real());
		ll cv=(ll)round(y[i].imag());
		av%=mod;bv%=mod;cv%=mod;
		res[i]=(av<<30)+(bv<<15)+cv;
		res[i]%=mod;
		res[i]+=mod;
		res[i]%=mod;
	}
	return res;
}

vector<ll> lagrange(vector<ll> h,ll p){
	auto mul=[p](ll a,ll b){
		return a*b%p;
	};
	auto ipow=[&mul](ll a,ll b){
		ll res=1;
		while(b){
			if(b&1)res=mul(res,a);
			a=mul(a,a);
			b>>=1;
		}
		return res;
	};
	auto modInv=[&ipow,p](ll a){
		return ipow(a,p-2);
	};
	
	int d=(int)h.size()-1;
	vector<ll> fct(4*d+2),invfct(4*d+2);
	fct[0]=1;
	for(int i=1;i<=d*4+1;i++)fct[i]=mul(i,fct[i-1]);
	invfct[4*d+1]=modInv(fct[4*d+1]);
	for(int i=4*d;i>=0;i--)invfct[i]=mul(invfct[i+1],i+1);
	vector<ll> f(d+1);
	for(int i=0;i<=d;i++){
		f[i]=h[i];
		f[i]=mul(invfct[i],f[i]);
		f[i]=mul(invfct[d-i],f[i]);
		if((d-i)%2==1)f[i]=p-f[i];
		if(f[i]==p)f[i]=0;
	}
	vector<ll> inv(4*d+2);
	for(int i=1;i<4*d+2;i++)inv[i]=mul(fct[i-1],invfct[i]);
	vector<ll> g(4*d+2);
	g[d+1]=1;
	for(int j=0;j<=d;j++)g[d+1]=mul(g[d+1],d+1-j);
	for(int i=d+2;i<4*d+2;i++)g[i]=mul(g[i-1],mul(i,inv[i-d-1]));
	vector<ll> conv=multiply(f,inv,p);
	vector<ll> res(4*d+2);
	for(int i=0;i<=d;i++)res[i]=h[i];
	for(int i=d+1;i<4*d+2;i++)res[i]=mul(g[i],conv[i]);
	return res;
}

vector<ll> squarepoly(vector<ll> pol,ll p){
	vector<ll> ss=lagrange(pol,p);
	vector<ll> res(ss.size()/2);
	for(int i=0;i<(int)ss.size()/2;i++)res[i]=ss[i<<1]*ss[(i<<1)|1]%p;
	return res;
}

int main(){
	ll n,p;
	cin>>n>>p;
	if(p<1000){
		ll res=1;
		for(ll i=1;i<=n;i++){
			res*=i;
			res%=p;
		}
		cout<<res;
		return 0;
	}
	ll d=1;
	vector<ll> fctprt={1%p,2%p};
	while(n>d*(d+1)){
		fctprt=squarepoly(fctprt,p);
		d<<=1;
	}
	ll res=1,bck=n/d;
	for(int i=0;i<bck;i++)res=res*fctprt[i]%p;
	for(ll i=bck*d+1;i<=n;i++)res=res*i%p;
	cout<<res;
}
