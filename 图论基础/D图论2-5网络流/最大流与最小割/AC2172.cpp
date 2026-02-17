#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long llong;
typedef unsigned long long ull;
#define  MAXN  300005

int head[MAXN], vex[MAXN], wgt[MAXN], nxt[MAXN], idx = 1;
int dep[MAXN], gap[MAXN], curr[MAXN], src, dst;
int n, m, a, b, c;

void add_edge(int x, int y, int w) {
    vex[++idx] = y, wgt[idx] = w, nxt[idx] = head[x], head[x] = idx;
}


void bfs(){
   memset(dep, 0, sizeof(dep));
   memset(gap, 0, sizeof(gap));
   dep[dst] = 1, gap[1] = 1; 
   
   queue<int> q;
   q.push(dst);
  
   while(q.size()){
       int u = q.front(); q.pop();
       for(int i = head[u]; i; i = nxt[i]){
           int v = vex[i], w = wgt[i];
           if(dep[v] == 0 && w == 0){
               dep[v] = dep[u] + 1;
               ++gap[dep[v]];
               q.push(v);
           }
       }
   }
}


llong dfs(int u, int iflow = 2e9){
    if(u == dst){
        return iflow;
    }
    int used = 0;
    for(int i = head[u]; i && iflow; i = nxt[i]){
        curr[u] = i;
        int v = vex[i], w = wgt[i];
        if(dep[v] + 1 == dep[u] && w > 0){
            llong ret = dfs(v, min(iflow - used, w));
            used += ret;
            wgt[i] -= ret;
            wgt[i ^ 1] += ret;
            if(used == iflow){
                return iflow;
            }
        }
    }
    if(--gap[dep[u]] == 0){
        dep[src] = n + 1;
    }
    ++dep[u];
    ++gap[dep[u]];
    return used;
}

llong isap(){
    bfs();
    llong flow = 0;
    while (dep[src] <= n) {
        memcpy(curr, head, sizeof(head));
        flow += dfs(src);
    }
    return flow;
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d %d %d %d", &n, &m, &src, &dst);
    for (int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        add_edge(a, b, c);
        add_edge(b, a, 0);
    }
    printf("%lld\n", isap());
    return 0;
}