#include<bits/stdc++.h>
using namespace std;

#define MAXN 205
#define INF  0x3f3f3f3f

int g[MAXN][MAXN], n, m, k, a, b, w;

void floyd(){
    for(int k = 1; k <= n; k++){
        g[k][k] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j<= n; j++){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

int main(){ 
    scanf("%d %d %d", &n, &m, &k);
    memset(g, 0x3f,sizeof(g));
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &w);
        g[a][b] = min(g[a][b], w);
    }
    floyd();
    for(int i = 0; i < k ; i++){
        scanf("%d %d", &a, &b);
        if(g[a][b] > INF / 2){
            printf("impossible\n");
        }else{
            printf("%d\n", g[a][b]);
        }
    }
    return 0;
}