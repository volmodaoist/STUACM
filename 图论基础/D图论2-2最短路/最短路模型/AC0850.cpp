#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 300000
typedef pair<int, int> ii;

int n, m, a, b, w;
int heads[MAXN], val[MAXN], wgt[MAXN], nxt[MAXN], idx;
int dist[MAXN], vist[MAXN];

void add_edge(int a, int b, int w){
    val[idx] = b;
    wgt[idx] = w;
    nxt[idx] = heads[a];
    heads[a] = idx++;
}

int dijstra(int src, int dst){
    memset(vist, 0, sizeof(vist));
    memset(dist, 0x3f, sizeof(dist));
    dist[src] = 1;
    
    priority_queue<ii, vector<ii>, greater<ii>> heap;
    heap.push({0,1});
    
    while(heap.size()){
        auto t = heap.top(); heap.pop();
        int dist_u = t.first, u = t.second;
        if(vist[u]){
            continue;
        }
        vist[u] = 1;
        
        // 此处下标非常容易弄错
        for(int i = heads[u]; ~i; i = nxt[i]){
            int v = val[i], w = wgt[i];
            if(dist[v] > dist_u + w){
                dist[v] = dist_u + w;
                heap.push({dist[v], v});
            }
        }
    }
    return (dist[dst] == 0x3f3f3f3f) ? -1 : dist[dst];
}

int main(){
    scanf("%d %d", &n, &m);
    memset(heads, -1, sizeof(heads));
    
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &w);
        add_edge(a, b, w);
    }
    printf("%d\n", dijstra(1, n));
    return 0;
}