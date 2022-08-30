#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 300000
#define INF  0x3f3f3f3f

typedef struct Edge{
    int a, b, w;
}Edge;

Edge edges[MAXN];
int n, m, k, a, b, w;
int dist[MAXN],  backup[MAXN];

int bellman_ford(int src, int dst){
    memset(dist, 0x3f, sizeof(dist));
    dist[src] = 0;
    for(int i = 0; i < k; i++){
        memcpy(backup, dist, sizeof(dist));
        for(int j  = 0; j < m; j++){
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
    return (dist[dst] > INF / 2) ? -INF : dist[dst]; 
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &w);
        edges[i] = {a, b, w};
    }
    int t = bellman_ford(1, n);
    if(t == -INF){
        printf("impossible\n");
    }else{
        printf("%d\n", t);   
    }
    return 0;
}