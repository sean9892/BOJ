#include<bits/stdc++.h>
using namespace std;

template<typename it,typename bi>
void _set(it x,vector<bool> const &in,bi lcs){
	for(vector<bool>::const_iterator xs=in.begin();xs!=in.end();++xs,++x){
		if(*xs){
			*lcs++=*x;
		}
	}
}

template<typename it>
void llen(it xl,it xh,it yl,it yh,vector<int> &l){
	vector<int> cur(1+distance(yl,yh),0);
	vector<int> prv(cur);
	for(it x=xl;x!=xh;++x){
		swap(prv,cur);
		int i=0;
		for(it y=yl;y!=yh;++y,++i){
			cur[i+1]=*x==*y?prv[i]+1:max(cur[i],prv[i+1]);
		}
	}
	swap(l,cur);
}

template<typename it>
void _calc(it xo,it xl,it xh,it yl,it yh,vector<bool>& in){
	const int l=distance(xl,xh);
	if(l==0)return;
	if(l==1){
		in[distance(xo,xl)]=find(yl,yh,*xl)!=yh;
		return;
	}
	it xm=xl+l/2;
	vector<int> vb,ve;
	reverse_iterator<it> hx(xh),mx(xm),hy(yh),ly(yl);
	llen(xl,xm,yl,yh,vb);
	llen(hx,mx,hy,ly,ve);
	vector<int>::const_reverse_iterator e=ve.rbegin();
	int lm=-1;
	it y=yl,ym=yl;
	for(vector<int>::const_iterator b=vb.begin();b!=vb.end();++b,++e){
		if(*b+*e>lm){
			lm=*b+*e;
			ym=y;
		}
		if(y!=yh)++y;
	}
	_calc(xo,xl,xm,yl,ym,in);
	_calc(xo,xm,xh,ym,yh,in);
}

void lcs(string const &xs,string const &ys,string &res){
	vector<bool> in(xs.size(),false);
	_calc(xs.begin(),xs.begin(),xs.end(),ys.begin(),ys.begin(),in);
	_set(xs.begin(),in,back_inserter(res));
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	string a,b,res;
	cin>>a>>b;
	lcs(a,b,res);
	cout<<res.size()<<"\n";
	cout<<res;
}
