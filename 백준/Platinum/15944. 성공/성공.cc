#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using pi3=pair<int,pii>;
#define cpi3(a,b,c) pi3((a),pii((b),(c)))
#define fi first
#define se second

const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

int N,M,D;
string arr[510];
int dst[510][510];

int vpos(int x,int y){
    return x>=0&&x<N&&y>=0&&y<M;
}

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    memset(dst,0x3f,sizeof(dst));
    dst[0][0]=0;
    cin>>N>>M>>D;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    priority_queue<pi3,vector<pi3>,greater<pi3>> q;
    q.push(cpi3(0,0,0));
    while(!q.empty()){
        int t,x,y;
        t=q.top().fi;
        tie(x,y)=q.top().se;
        q.pop();
        
        if(t>dst[x][y])continue;
        
        //without bomb
        for(int d=0;d<4;d++){
            int nx=x+dx[d],ny=y+dy[d];
            if(!vpos(nx,ny))continue;
            if(arr[nx][ny]=='.'&&t<dst[nx][ny]){
                dst[nx][ny]=t;
                q.push(cpi3(t,nx,ny));
            }
        }

        //with bomb
        if(abs(N-1-x)<=D&&abs(M-1-y)<=D&&(abs(N-1-x)<D||abs(M-1-y)<D)){
            dst[N-1][M-1]=min(dst[N-1][M-1],t+1);
        }
        for(int d=0,ld=(d+3)%4;d<4;d++,ld=(ld+1)%4){
            for(int i=-D+1;i<D;i++){
                int nx=x+D*dx[d]+i*dx[ld];
                int ny=y+D*dy[d]+i*dy[ld];
                if(!vpos(nx,ny))continue;
                if(dst[nx][ny]>t+1){
                    dst[nx][ny]=t+1;
                    q.push(cpi3(t+1,nx,ny));
                }
            }
        }
    }
    cout<<dst[N-1][M-1];
}