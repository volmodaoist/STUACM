#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 300000
int heads[MAXN], val[MAXN], wgt[MAXN], nxt[MAXN], idx;
int dist[MAXN], cnt[MAXN], waiting[MAXN];
int n, m, a, b, w;

void add_edge(int a, int b, int w){
    val[idx] = b;
    wgt[idx] = w;
    nxt[idx] = heads[a];
    heads[a] = idx++;
}

bool spfa(){
    queue <int> q;
    for(int i = 1; i <= n; i++){
        q.push(i);
        waiting[i] = 1;   
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        waiting[u] = 0;
        for(int i = heads[u]; ~i; i = nxt[i]){
            int v = val[i], w = wgt[i];
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1;
                if(cnt[v] >= n){
                    return true;
                }
                if(!waiting[v]){
                    q.push(v);
                    waiting[v] = 1;
                }
            }
        }
    }
    return false;
}

int main(){
    scanf("%d %d", &n, &m);
    memset(heads, -1, sizeof(heads));
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &w);
        add_edge(a, b, w);
    }
    printf("%s\n", spfa() ? "Yes" : "No");
    return 0;
}