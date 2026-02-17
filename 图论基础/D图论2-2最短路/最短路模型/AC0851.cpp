#include<bits/stdc++.h>
using namespace std;

#define MAXN 300000
#define INF  0x3f3f3f3f

typedef pair<int, int> ii;

int heads[MAXN], val[MAXN], wgt[MAXN], nxt[MAXN], idx;
int waiting[MAXN], dist[MAXN];
int n, m, a, b, w;

void add_edge(int a, int b, int w){
    val[idx] = b;
    wgt[idx] = w;
    nxt[idx] = heads[a];
    heads[a] = idx++;
}

int spfa(){
    queue<ii> q;
    memset(dist, 0x3f, sizeof(dist));
    
    dist[1] = 0;
    waiting[1] = 1;
    
    q.push({0, 1});
    
    while(!q.empty()){
        auto t  = q.front(); q.pop();
        int dist_u = t.first, u = t.second;
        waiting[u] = false;
        
        for(int i = heads[u]; ~i; i = nxt[i]){
            int v = val[i], w = wgt[i];
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                if(!waiting[v]){
                    waiting[v] = 1;
                    q.push({dist[v], v});
                }
            }
        }
    }
    return (dist[n] == INF) ? -INF : dist[n];
}

int main(){
    scanf("%d %d", &n, &m);
    memset(heads, -1, sizeof(heads));
    for(int  i = 0; i < m ; i++){
        scanf("%d %d %d", &a, &b, &w);
        add_edge(a, b, w);
    }
    int t = spfa();
    if(t == -INF){
       printf("impossible\n"); 
    }else{
        printf("%d\n", t);
    }
    return 0;
}