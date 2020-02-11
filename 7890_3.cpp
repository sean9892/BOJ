#include <bits/stdc++.h>
using namespace std;
using ll=long long; 
using dot= pair<ll,ll>;

#define fi first
#define se second
 
struct node {
	dot pt;
	bool st;
	ll sx,ex,sy,ey;
};
 
node kdt[300010];
int n,ex[300010];
dot point[100010];
ll mdst;
dot vv[100010];
 
ll sq(long long a){
	return a*a;
}
 
bool xcomp(dot a,dot b){
	if(a.fi^b.fi)return a.fi<b.fi;
	return a.se<b.se;
}
 
bool ycomp(dot a,dot b){
	if(a.se^b.se)return a.se<b.se;
	return a.fi<b.fi;
}
 
void mktree(int l,int r,int idx){
	ll minx=2e9,maxx=-2e9,miny=2e9,maxy=-2e9;
	for(int i=l;i<=r;i++) {
		minx=min(minx,point[i].fi);
		maxx=max(maxx,point[i].fi);
		miny=min(miny,point[i].se);
		maxy=max(maxy,point[i].se);
	}
	kdt[idx].sx=minx;
	kdt[idx].ex=maxx;
	kdt[idx].sy=miny;
	kdt[idx].ey=maxy;
	ex[idx]=true;
    if(idx==1)kdt[idx].st=0;
    else kdt[idx].st=!kdt[idx/2].st;
	if(kdt[idx].st)sort(point+l,point+r+1,ycomp);
	else sort(point+l,point+r+1,xcomp);
	int m=l+r>>1;
	kdt[idx].pt=point[m];
	if(l<m)mktree(l,m-1,idx*2);
	if(m<r)mktree(m+1,r,idx*2+1);
}
 
void nns(int idx,dot now){
	if(now!=kdt[idx].pt)mdst=min(mdst,sq(kdt[idx].pt.first-now.first)+sq(kdt[idx].pt.se-now.se));
	if(kdt[idx].st){
		if(!ycomp(kdt[idx].pt,now)){
			if(ex[idx*2])nns(idx*2,now);
			if(ex[idx*2+1]&&sq(kdt[idx*2+1].sy-now.se)<mdst)nns(idx*2+1,now);
		}
		else{
			if(ex[idx*2+1])nns(idx*2+1,now);
			if(ex[idx*2]&&sq(kdt[idx*2].ey-now.se)<mdst)nns(idx*2,now);
		}
	}
	else{
		if(!xcomp(kdt[idx].pt,now)) {
			if(ex[idx*2])nns(idx*2,now);
			if(ex[idx*2+1]&&sq(kdt[idx*2+1].sx-now.fi)<mdst)nns(idx*2+1,now);
		}
		else{
			if(ex[idx*2+1])nns(idx*2+1,now);
			if(ex[idx*2]&&sq(kdt[idx*2].ex-now.fi)<mdst)nns(idx*2,now);
		}
	}
}

void TC(){
	memset(ex,0,sizeof(ex));
	int n;
	cin>>n;
    vector<dot> tmp;
	for(int i=0;i<n;i++) {
		int x,y;
		cin>>x>>y;
		tmp.push_back({x,y});
		vv[i]=tmp[i];
	}
	sort(tmp.begin(),tmp.end(),xcomp);
    vector<dot> doub;
	point[0]=tmp[0];
	int cnt=1;
	for(int i=1;i<tmp.size();i++) {
	    if (tmp[i-1]!=tmp[i]) {
	        point[cnt++]=tmp[i];
	    }
        else {
            doub.push_back(tmp[i]);
        }
	}
	mktree(0,cnt-1,1);
	for(int i=0;i<n;i++) {
        if (!doub.empty()&&*lower_bound(doub.begin(),doub.end(),vv[i])==vv[i]) {
            cout<<"0\n";
        }
        else {
		    mdst=5e18;
		    nns(1,vv[i]);
		    cout<<mdst<<"\n";
        }
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
