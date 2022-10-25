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
#define  MAXN  100005

// 此处一个细节便是 idx = 1 而非 0
int head[MAXN], vex[MAXN], wgt[MAXN], nxt[MAXN], idx = 1;
int mf[MAXN], prec[MAXN], src, dst;
int n, m, a, b, c;

// mf[v] 存储源点到达顶点 v 所允许的最大流量
void add_edge(int x, int y, int w) {
    vex[++idx] = y, wgt[idx] = w, nxt[idx] = head[x], head[x] = idx;
}

bool bfs(){
    memset(mf, 0, sizeof(mf));
    mf[src] = 2e9;

    queue<int> q;
    q.push(src);

    while(q.size()){
        int u  = q.front(); q.pop();
        for (int i = head[u]; i; i = nxt[i]){
            int v = vex[i], w = wgt[i];
            if (mf[v] == 0 && w > 0) {
                mf[v] = min(mf[u], w);
                prec[v] = i;
                q.push(v);
                if(v == dst) return true;
            }
        }
    }
    return false;
}

// EK 算法是对 FF 算法的一个优化
llong EK(){
    llong flow = 0;
    while(bfs()){
        for (int v = dst, i = prec[v]; v != src; v = vex[i ^ 1], i = prec[v]) {
            wgt[i] -= mf[dst];
            wgt[i ^ 1] += mf[dst];
        }
        flow += mf[dst];
    }
    return flow;
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d %d %d %d", &n, &m, &src, &dst);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        add_edge(a, b, c);
        add_edge(b, a, 0);
    }
    printf("%lld\n", EK());
    return 0;
}