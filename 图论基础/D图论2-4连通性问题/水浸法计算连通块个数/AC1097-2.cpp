#include<bits/stdc++.h>
using namespace std;

#define MAXN 1005
char farm[MAXN][MAXN];
int vist[MAXN][MAXN];
typedef pair<int, int> ii;

int n, m;
int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};


void bfs(int x, int y, int tag){
    queue<ii> q;
    q.push({x,y});
    vist[x][y] = tag;
    while(q.size()){
        auto [x,y] = q.front(); q.pop();
        for(int k = 0; k < 8; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vist[nx][ny] &&farm[nx][ny] == 'W'){
                q.push({nx, ny});
                vist[nx][ny] = tag;
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%s", farm[i]);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(farm[i][j] == 'W' && !vist[i][j]){
                bfs(i, j, ++cnt);
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}