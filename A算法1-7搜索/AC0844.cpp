#include<bits/stdc++.h>
using namespace std;

#define MAXN 300

int n, m;
int maze[MAXN][MAXN];
bool vist[MAXN][MAXN];

typedef struct node{
    int x,y,step;    
}node;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &maze[i][j]);            
        }
    }
    queue<node> q;
    
    q.push({1,1,0});
    vist[1][1] = true;
    
    while(!q.empty()){
        auto t = q.front(); q.pop();
        if(t.x == n && t.y == m){
            printf("%d\n", t.step);
            break;
        }
        for(int i = 0; i < 4; i++){
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vist[nx][ny] && !maze[nx][ny]){
                vist[nx][ny] = true;
                q.push({nx, ny, t.step + 1});
            }
        }
    }
    return 0;
}