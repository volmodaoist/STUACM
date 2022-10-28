#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
#define  MAXN  100005

int n, m, a, b, c, pos, src, dst;
int head[MAXN], vex[MAXN], wgt[MAXN], nxt[MAXN], idx = 1;
int dep[MAXN], curr[MAXN];

void add_edge(int a, int b, int w) {
    vex[++idx] = b, wgt[idx] = w, nxt[idx] = head[a], head[a] = idx;
}

bool bfs(){
    memset(dep, 0, sizeof(dep));
    memcpy(curr, head, sizeof(head));
    dep[src] = 1;

    queue<int> q;
    q.push(src);

    while(q.size()){
        int u = q.front(); q.pop();
        for (int i = head[u]; i; i = nxt[i]){
            int v = vex[i], w = wgt[i];
            if (dep[v] == 0 && w > 0){
                dep[v] = dep[u] + 1;
                q.push(v);
            }
        }
    }
    return dep[dst] != 0;
}

int dfs(int u, int iflow = 2e9){
    if(u == dst){
        return iflow;
    }
    int oflow = 0;
    for (int i = curr[u]; i && iflow; i = nxt[i]) {
        curr[u] = i;
        int v = vex[i], w = wgt[i];
        if(dep[v] == dep[u] + 1 && w > 0){
            int ret = dfs(v, min(iflow, w));
            wgt[i] -= ret, oflow += ret;
            wgt[i ^ 1] += ret, iflow -= ret;
        }
    }
    return oflow ? oflow : (dep[u] = 0);
}

int dinic(){
    int ans = 0;
    while (bfs()){
        ans += dfs(src);
    }
    return ans;
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d %d", &n, &m);
    src = 0;
    dst = n + 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &pos);
        if (pos){
            add_edge(src, i, 1); add_edge(i, src, 0);
        }else{
            add_edge(i, dst, 1); add_edge(dst, i, 0);
        }
    }
    for (int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        add_edge(a, b, 1); add_edge(b, a, 0);
        add_edge(b, a, 1); add_edge(a, b, 0);
    }
    printf("%d\n", dinic());
    return 0;
}