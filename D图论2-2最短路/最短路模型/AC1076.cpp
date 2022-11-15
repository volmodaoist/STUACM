#include<bits/stdc++.h>
using namespace std;

#define MAXN 1005
typedef pair<int, int> ii; 
int n, g[MAXN][MAXN], prec[MAXN][MAXN], vist[MAXN][MAXN];
int dx[4] = {0,  -1, 0, 1};
int dy[4] = {-1, 0, 1,  0};

bool bfs(int sx, int sy){
    queue<ii> q; q.push({sx,sy}); vist[sx][sy] = 1;
    while(q.size()){
        auto [x, y] = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n  && !vist[nx][ny] && !g[nx][ny]){
                prec[nx][ny] = 10000 * x + y;
                vist[nx][ny] = 1;
                if(nx == n - 1 && ny == n - 1){
                    return true;
                }
                q.push({nx, ny});
            }
        }
    }
    return false;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &g[i][j]);
        }
    }
    bfs(0, 0);
    int  x, y, curx = n - 1, cury = n - 1;
    stack<ii> stk;
    stk.push({curx, cury});
    while(prec[curx][cury]){
        x = prec[curx][cury] / 10000;
        y = prec[curx][cury] % 10000;
        curx = x;
        cury = y;
        stk.push({curx, cury});
    }
     stk.push({0, 0});
    while(stk.size()){
        auto [x,y] = stk.top(); stk.pop();
        printf("%d %d\n", x, y);
    }
    return 0;
}