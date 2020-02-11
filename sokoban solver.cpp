#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct data{
    int x, y, sx, sy, d;
    data(){}
    data(int x, int y, int sx, int sy, int d): x(x), y(y), sx(sx), sy(sy), d(d){}
};

int n, m;
int x, y;
int sx, sy, dx, dy;
char board[62][62];
bool visited[62][62][62][62];
data recent[62][62][62][62];
char chr[4] = {'R', 'D', 'L', 'U'};
queue<data> que;
vector<char> vec;

int xx[]={0, 1, 0, -1}, yy[]={1, 0, -1, 0};

bool isInside(int a, int b, int c, int d){
    return ((c==a)||(c==a+1)) && ((d==b)||(d==b+1));
}
bool isOut(int a, int b){
    return a<1||a>n||b<1||b>m;
}
bool isAble(int a, int b){
    for(int i=0; i<2; i++) for(int j=0; j<2; j++){
        if(isOut(a+i, b+j) || board[a+i][b+j]=='#') return 0;
    }
    return 1;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        scanf("%s", board[i]+1);
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(board[i][j] == 'P') x=i, y=j;
            else if(board[i][j] == 'S' && !dx) dx=i, dy=j;
            else if(board[i][j] == 'B' && !sx) sx=i, sy=j;
        }
    }

    que.push(data(x, y, sx, sy, 0));
    visited[x][y][sx][sy] = 1;
    while(!que.empty()){
        data tmp = que.front();
        que.pop();
        int tx=tmp.x, ty=tmp.y, tsx=tmp.sx, tsy=tmp.sy, td=tmp.d;

        if(tsx==dx && tsy==dy){
            printf("Got answer: %d times\n", td);
            while(tmp.d){
                data ttmp = recent[tmp.x][tmp.y][tmp.sx][tmp.sy];
                for(int i=0; i<4; i++){
                    if(ttmp.x+xx[i] == tmp.x && ttmp.y+yy[i] == tmp.y){
                        vec.push_back(chr[i]);
                        break;
                    }
                }
                tmp=ttmp;
            }
            while(!vec.empty()){
                printf("%c", vec.back());
                vec.pop_back();
            }
            break;
        }

        for(int i=0; i<4; i++){
            /// 만약 상자 칸일 때
            int ttx=tx+xx[i], tty=ty+yy[i];
            if(ttx<1||ttx>n||tty<1||tty>m) continue;
            if(isInside(tsx, tsy, ttx, tty)){
                int ttsx=tsx+xx[i], ttsy=tsy+yy[i];
                if(isAble(ttsx, ttsy) && !visited[ttx][tty][ttsx][ttsy]){
                    que.push(data(ttx, tty, ttsx, ttsy, td+1));
                    visited[ttx][tty][ttsx][ttsy] = 1;
                    recent[ttx][tty][ttsx][ttsy] = tmp;
                }
            }
            else if(board[ttx][tty] == '#') continue;
            else if(!visited[ttx][tty][tsx][tsy]){
                que.push(data(ttx, tty, tsx, tsy, td+1));
                visited[ttx][tty][tsx][tsy] = 1;
                recent[ttx][tty][tsx][tsy] = tmp;
            }
        }
    }
}
