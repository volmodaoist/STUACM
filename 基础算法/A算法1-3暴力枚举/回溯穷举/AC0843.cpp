#include<bits/stdc++.h>
using namespace std;

#define MAXN 20
char maze[MAXN][MAXN];
int cols[MAXN], dg[MAXN], udg[MAXN];

int n;
void dfs(int x){
    if(x == n){
        for(int i = 0; i < n; i++){
            printf("%s\n", maze[i]);
        }
        printf("\n");
        return;
    }
    for(int y = 0; y < n; y++){
        if(maze[x][y] == '.' && !cols[y] && !udg[y - x + n] && !dg[y + x]){
            maze[x][y] = 'Q';
            cols[y] = udg[y - x + n] = dg[y + x] = true;
            dfs(x + 1);
            cols[y] = udg[y - x + n] = dg[y + x] = false;
            maze[x][y] = '.';
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            maze[i][j] = '.';
        }
    }
    dfs(0);
    return 0;
}