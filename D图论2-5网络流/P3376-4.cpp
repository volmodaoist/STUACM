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
#define  MAXN  300005

// 此处一个细节便是 idx = 1 而非 0
int head[MAXN], vex[MAXN], wgt[MAXN], nxt[MAXN], idx = 1;
int dep[MAXN], curr[MAXN], src, dst;
int n, m, a, b, c;

// mf[v] 存储源点到达顶点 v 所允许的最大流量
void add_edge(int x, int y, int w) {
    vex[++idx] = y, wgt[idx] = w, nxt[idx] = head[x], head[x] = idx;
}

//深度初始化-1 也是可以的
bool bfs(){
    memset(dep, 0, sizeof(dep));
    memcpy(curr, head, sizeof(head));

    dep[src] = 1;

    queue<int> q;
    q.push(src);

    while(q.size()){
        int u  = q.front();q.pop();
        for(int i = head[u]; i; i = nxt[i]) {
            int v = vex[i], w = wgt[i];
            if (dep[v] == 0 && w > 0) {
                dep[v] = dep[u] + 1;
                q.push(v);
                if (v == dst) return true;
            }
        }
    }
    return false;
}

// Dinic 另外一个版本的写法
ill dfs(int u, int iflow = 2e9){
    if(u == dst){
        return iflow;
    }
    ill used = 0;
    for (int i = curr[u]; i && iflow; i = nxt[i]) {
        curr[u] = i;
        int v = vex[i], w = wgt[i];
        if (dep[v] == dep[u] + 1 && w > 0) {
            // 个别模板会把参数 iflow 当做常量，然后递归 dfs 传参的时候写成相减形式
            ill ret = dfs(v, min(iflow - used, 0LL + w));
            wgt[i] -= ret;
            wgt[i ^ 1] += ret;
            used += ret;
            if(used == iflow){
                return iflow;
            }
        }
    }
    return used;
}


ill Dinic(){
    ill flow = 0;
    while(bfs()){
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
    printf("%lld\n", Dinic());
    return 0;
}