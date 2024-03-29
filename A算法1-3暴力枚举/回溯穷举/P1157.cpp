#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define  MAXN  100005

int n, r;
int x[MAXN], vis[MAXN], path[MAXN];

void dfs(int start, int plen, int n, int r) {
    if(plen == r){
        for (int i = 0; i < plen; i++){
            printf("%3d", path[i]);
        }
        printf("\n");
        return;
    }
    for (int i = start; i < n; i++){
        if(!vis[i]){
            vis[i] = 1;
            path[plen] = x[i];
            dfs(i + 1, plen + 1, n, r);
            path[plen] = 0;
            vis[i] = 0;
        }
    }
}


int main(){ 
    scanf("%d %d", &n, &r);
    for (int i = 0; i < n; i++){
        x[i] = i + 1;
    }
    dfs(0, 0, n, r);
    return 0;
}