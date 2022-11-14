#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
#define	 INF   0x3f3f3f3f
#define  MAXN  200005

int a, b, c, m, n, src, dst;
int head[MAXN], vex[MAXN], wgt[MAXN], nxt[MAXN], idx = 1;
int curr[MAXN], dep[MAXN];

void add_edge(int x, int y, int w) {
    vex[++idx] = y, wgt[idx] = w, nxt[idx] = head[x], head[x] = idx;
    vex[++idx] = x, wgt[idx] = 0, nxt[idx] = head[y], head[y] = idx;
}

bool bfs(){
    memset(dep, 0, sizeof(dep));
    memcpy(curr, head, sizeof(head));
    dep[src] = 1;

    queue<int> q;
    q.push(src);

    while(q.size()){
        int u = q.front(); q.pop();
        for (int i = head[u]; i; i = nxt[i]) {
            int v = vex[i], w = wgt[i];
            if(dep[v] == 0 && w > 0){
                dep[v] = dep[u] + 1;
                q.push(v);
            }
        }
    }
    return dep[dst] != 0;
}

int dfs(int u, int iflow = INF){
    if(u == dst){
        return iflow;
    }
    int oflow = 0;
    for (int i = curr[u]; i && iflow; i = nxt[i]){
        curr[u] = i;
        int v = vex[i], w = wgt[i];
        if (dep[v] == dep[u] + 1 && w > 0) {
            int ret = dfs(v, min(iflow, w));
            wgt[i] -= ret, iflow -= ret;
            wgt[i ^ 1] += ret, oflow += ret;
        }
    }
    return oflow ? oflow : (dep[u] = 0);
}


int dinic(){
    int ans = 0;
    while(bfs()){
        int tmp = dfs(src);
        ans += tmp;
    }
    return ans;
}

void debug_print_edge(int u){
    for (int i = head[u]; i; i = nxt[i]){
        int v = vex[i], w = wgt[i];
        printf("(%d,%d, w = %d)\n", u, v, w);
    }
    printf("\n");
}

int main(){ 
    scanf("%d %d %d %d", &n, &m, &src, &dst);
    for (int i = 1; i <= n; i++){
        add_edge(i, i + n, 1);
    }
    // 本题的难点在于建图，非常容易出错
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        add_edge(a + n, b, INF);
        add_edge(b + n, a, INF);
    }
    src += n;
    printf("%d\n", dinic());
    return 0;
}