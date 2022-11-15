#include<bits/stdc++.h>
using namespace std;

#define MAXN 1005
int n, nx, ny, tx, ty, cntA, cntV;
int maze[MAXN][MAXN], vist[MAXN][MAXN];
typedef pair<int,int> ii;
int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};


bool check(int nx, int ny){
    return nx < 0 || nx >= n || ny < 0 || ny >= n;
}

// 先打印山峰、山谷
void bfs(int sx, int sy){
    bool fg1 = true, fg2 = true;
    queue<ii> q; q.push({sx, sy}); vist[sx][sy] = 1;
    while(q.size()){
        auto [x,y] = q.front(); q.pop();
        for(int i = 0; i < 8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(check(nx, ny)) 
                continue;
            if(maze[nx][ny] == maze[sx][sy] && !vist[nx][ny]){
                vist[nx][ny] = 1;
                q.push({nx, ny});
            }else if(maze[nx][ny] > maze[sx][sy]){
                fg1 = false;
            }else if(maze[nx][ny] < maze[sx][sy]){
                fg2 = false;
            }
        } 
    }
    if(fg1) cntA++;
    if(fg2) cntV++;
}

void printMaze(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", vist[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &maze[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!vist[i][j]){
                bfs(i, j);
            }
        }
    }
    printf("%d %d\n", cntA, cntV);
    return 0;
}