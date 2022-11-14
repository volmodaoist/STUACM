#include<bits/stdc++.h>
using namespace std;

#define MAXN 55
typedef pair<int, int> ii;
int n, m, maze[MAXN][MAXN], vist[MAXN][MAXN];
int dx[4] = {0,  -1, 0, 1};
int dy[4] = {-1, 0, 1,  0};

int bfs(int x, int y, int tag){
    int ret = 0;
    queue<ii> q; q.push({x,y}); 
    vist[x][y] = tag;
    while(q.size()){
        auto [x,y] = q.front(); q.pop(); ret++;
        for(int i = 0; i < 4; i++){
            if(!(maze[x][y] >> i & 1)){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vist[nx][ny]){
                    vist[nx][ny] = tag;
                    q.push({nx, ny});
                }
            }
        }
    }
    return ret;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &maze[i][j]);
        }
    }
    int cnt = 0, area = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!vist[i][j]){
                area = max(area, bfs(i, j, ++cnt));
            }
        }
    }
    printf("%d\n%d\n", cnt, area);
    return 0;
}