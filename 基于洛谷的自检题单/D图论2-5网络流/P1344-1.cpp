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


typedef long long llong;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
#define  MAXN  200005

llong a[MAXN], b[MAXN], c, n, m, src, dst;
llong head[MAXN], vex[MAXN], wgt[MAXN], nxt[MAXN], idx = 1;
llong dep[MAXN], curr[MAXN];

void init_edge() {
    memset(head, 0, sizeof(head));
    idx = 1;
}

void add_edge(llong a, llong b, llong w){
    vex[++idx] = b, wgt[idx] = w, nxt[idx] = head[a], head[a] = idx;
}

bool bfs(){
    memcpy(curr, head, sizeof(head));
    memset(dep, 0, sizeof(dep));
    dep[src] = 1;

    queue<int> q;
    q.push(src);

    while (q.size()){
        llong u = q.front(); q.pop();
        for (int i = head[u]; i; i = nxt[i]){
            llong v = vex[i], w = wgt[i];
            if (dep[v] == 0 && w > 0){
                dep[v] = dep[u] + 1;
                q.push(v);
            }
        }
    }
    return dep[dst] != 0;
}

llong dfs(llong u, llong iflow = LONG_MAX){
    if(u == dst){
        return iflow;
    }
    llong used = 0;
    for (int i = curr[u]; i; i = nxt[i]) {
        curr[u] = i;
        llong v = vex[i], w = wgt[i];
        if(dep[v] == dep[u] + 1 && w > 0){
            llong ret = dfs(v, min(iflow - used, w));
            wgt[i] -= ret;
            wgt[i ^ 1] += ret;
            used += ret;
            if(used == iflow){
                return used;
            }
        }
    }
    return used ? used : (dep[u] = 0);//残枝优化
}

llong dinic(){
    llong ans = 0;
    while (bfs()) {
        ans += dfs(src);
    }
    return ans;
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int offset = 1331;
    scanf("%lld %lld", &n, &m);
    for (int i = 0; i < m; i++){
        scanf("%lld %lld %lld", &a[i], &b[i], &c);
        add_edge(a[i], b[i], c * offset + 1);
        add_edge(b[i], a[i], 0);
        
        n = max(max(a[i], b[i]), n);// 这句代码是因为hack 数据弄错不得不加上的
    }
    src = 1, dst = n;
    llong ans = dinic();
    printf("%lld %lld\n", ans / offset, ans % offset);
    return 0;
}