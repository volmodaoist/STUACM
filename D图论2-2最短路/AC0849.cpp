#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

#define MAXN 550
int g[MAXN][MAXN];
int dist[MAXN], vist[MAXN], n, m;

int a, b, w;
int dijstra(int src, int dst){
    memset(vist, 0, sizeof(vist));
    memset(dist, 0x3f, sizeof(dist));
    dist[src] = 0;
    for(int i = 0; i < n; i++){
        int  t = -1;
        for(int j = 1; j <= n; j++){
            if(!vist[j] &&(t == -1 || dist[t] > dist[j])){
                t = j;
            }
        }
        vist[t] = 1;
        for(int j = 1; j <= n; j++){
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    return (dist[dst] == 0x3f3f3f3f) ? -1 : dist[dst];
}


int main(){
    scanf("%d %d", &n, &m);
    memset(g, 0x3f, sizeof(g));
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &w);
        g[a][b] = min(g[a][b], w);
    }
    printf("%d\n", dijstra(1, n));
    return 0;
}