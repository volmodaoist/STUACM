#include<bits/stdc++.h>
using namespace std;

#define MAXN 200
char maze[MAXN][MAXN];
typedef pair<int, int> ii;
int dx[8] = {-2, -2, +1, +1, -1, -1, +2, +2};
int dy[8] = {+1, -1, +2, -2, +2, -2, +1, -1};
int dist[MAXN][MAXN];
int r, c, sx, sy, hx, hy;

int bfs(int sx, int sy){
    int layers = 0;
    queue<ii> q; q.push({sx, sy}); dist[sx][sy] = 0;
    while(q.size()){
        int len = q.size();
        for(int k = 0; k < len; k++){
            auto [x, y] = q.front(); q.pop();
            for(int i = 0; i < 8; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < r && ny >= 0 && ny < c && dist[nx][ny] == -1 && maze[nx][ny] != '*'){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        layers++;
    }
    return layers;
}

int main(){
    scanf("%d %d", &c, &r);
    memset(dist, -1 ,sizeof(dist));
    for(int i = 0; i < r; i++){
        scanf("%s", maze[i]);
        for(int j = 0; j < c; j++){
            if(maze[i][j] == 'K') sx = i, sy = j;
            if(maze[i][j] == 'H') hx = i, hy = j;
        }
    }
    bfs(sx, sy);
    printf("%d\n", dist[hx][hy]);
    return 0;
}