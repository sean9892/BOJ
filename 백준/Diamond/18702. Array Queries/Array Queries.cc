#include<bits/stdc++.h>
using namespace std;
using ll=long long;

inline int readChar();
template<class T = int> inline T readInt();
template<class T> inline void writeInt(T x, char end = 0);
inline void writeChar(int x);
inline void writeWord(const char *s);
static const int buf_size = 1 << 18;
inline int getChar(){
   static char buf[buf_size];
   static int len = 0, pos = 0;
   if(pos == len) pos = 0, len = fread(buf, 1, buf_size, stdin);
   if(pos == len) return -1;
   return buf[pos++];
}
inline int readChar(){
   int c = getChar();
   while(c <= 32) c = getChar();
   return c;
}
template <class T>
inline T readInt(){
   int s = 1, c = readChar();
   T x = 0;
   if(c == '-') s = -1, c = getChar();
   while('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
   return s == 1 ? x : -x;
}
static int write_pos = 0;
static char write_buf[buf_size];
inline void writeChar(int x){
   if(write_pos == buf_size) fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
   write_buf[write_pos++] = x;
}
template <class T> 
inline void writeInt(T x, char end){
   if(x < 0) writeChar('-'), x = -x;
   char s[24]; int n = 0;
   while(x || !n) s[n++] = '0' + x % 10, x /= 10;
   while(n--) writeChar(s[n]);
   if(end) writeChar(end);
}
inline void writeWord(const char *s){
   while(*s) writeChar(*s++);
}
struct Flusher{
   ~Flusher(){ if(write_pos) fwrite(write_buf, 1, write_pos, stdout), write_pos = 0; }
}flusher;

const int nmax=1e5+10;

ll sq(ll x){
	return (ll)sqrt(x);
}

struct node{
	ll hi,lo,sum;
};

node f(node a,node b){
	node r;
	r.hi=max(a.hi,b.hi);
	r.lo=min(a.lo,b.lo);
	r.sum=a.sum+b.sum;
	return r;
}

node seg[nmax<<2];
ll arr[nmax];
ll l1[nmax<<2],l2[nmax<<2];//l1*x+l2

void init(int idx,int l,int r){
	if(l==r){
		seg[idx].hi=seg[idx].lo=seg[idx].sum=arr[l];
		return;
	}
	int m=l+r>>1,le=idx<<1,ri=le|1;
	init(le,l,m);init(ri,m+1,r);
	seg[idx]=f(seg[le],seg[ri]);
}

void prop(int idx,int l,int r){
	if(l1[idx]==1&&l2[idx]==0)return;
	seg[idx].lo*=l1[idx];seg[idx].hi*=l1[idx];seg[idx].sum*=l1[idx];
	seg[idx].lo+=l2[idx];seg[idx].hi+=l2[idx];seg[idx].sum+=l2[idx]*(r-l+1);
	if(l!=r){
		for(int i:{idx<<1,(idx<<1)+1}){
			l1[i]*=l1[idx];l2[i]*=l1[idx];l2[i]+=l2[idx];
		}
	}
	l1[idx]=1;l2[idx]=0;
}

void updsq(int idx,int l,int r,int s,int e){
	prop(idx,l,r);
	if(l>e||r<s||seg[idx].hi==0)return;
	if(s<=l&&r<=e){
		ll hsq=sq(seg[idx].hi),lsq=sq(seg[idx].lo);
		if(hsq==lsq){
			l1[idx]=0;l2[idx]=hsq;
			prop(idx,l,r);
			return;
		}
		if(seg[idx].hi==seg[idx].lo+1){
			l1[idx]=1;l2[idx]=lsq-seg[idx].lo;
			prop(idx,l,r);
			return;
		}
	}
	int m=l+r>>1,le=idx<<1,ri=le|1;
	updsq(le,l,m,s,e);updsq(ri,m+1,r,s,e);
	seg[idx]=f(seg[le],seg[ri]);
}

void updpl(int idx,int l,int r,int s,int e,ll x){
	prop(idx,l,r);
	if(l>e||r<s)return;
	if(s<=l&&r<=e){
		l2[idx]=x;
		prop(idx,l,r);
		return;
	}
	int m=l+r>>1,le=idx<<1,ri=le|1;
	updpl(le,l,m,s,e,x);updpl(ri,m+1,r,s,e,x);
	seg[idx]=f(seg[le],seg[ri]);
}

ll query(int idx,int l,int r,int s,int e){
	prop(idx,l,r);
	if(l>e||r<s)return 0;
	if(s<=l&&r<=e)return seg[idx].sum;
	int m=l+r>>1,le=idx<<1,ri=le|1;
	return query(le,l,m,s,e)+query(ri,m+1,r,s,e);
}

void TC(){
	int n,m;
	n=readInt();m=readInt();
	for(int i=1;i<=n;i++){
		arr[i]=readInt();
	}
	init(1,1,n);
	fill(l1,l1+(nmax<<2),1);
	memset(l2,0,sizeof(l2));
	for(int i=0;i<m;i++){
		int a=readInt();
		int b=readInt();
		int c=readInt();
		ll x;
		if(a==3){
			x=readInt();
			updpl(1,1,n,b,c,x);
		}
		if(a==1){
			updsq(1,1,n,b,c);
		}
		if(a==2){
			writeInt(query(1,1,n,b,c),'\n');
		}
	}
}

int main(void){
	int tc=readInt();
	while(tc--){
		TC();
	}
}