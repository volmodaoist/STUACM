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

int n, m, a, b, w, c, src, dst;
int head[MAXN], vex[MAXN], wgt[MAXN], pay[MAXN], nxt[MAXN], idx = 1;
int curr[MAXN], prec[MAXN], mf[MAXN], cost[MAXN], inq[MAXN];

void add_edge(int x, int y, int w, int c){
    vex[++idx] = y, wgt[idx] = w, pay[idx] = c, nxt[idx] = head[x], head[x] = idx;
}

// 费用流问题只需要修改EK 算法的 BFS，改成 SPFA 即可，但是当费用出现负环的时候无法解决，此时必须消圈算法
bool spfa(){
    memset(cost, 0x3f, sizeof(cost));
    memset(mf, 0, sizeof(mf));
    queue<int> q;
    q.push(src); cost[src] = 0, mf[src] = 2e9, inq[src] = 1;
    while (q.size()) {
        int u = q.front(); q.pop(); inq[u] = 0;
        for (int i = head[u]; i; i = nxt[i]){
            int v = vex[i], w = wgt[i], c = pay[i];
            if (cost[v] > cost[u] + c && w > 0) {
                cost[v] = cost[u] + c;
                mf[v] = min(mf[u], w);
                prec[v] = i;
                if(!inq[v]){
                    q.push(v); inq[v] = 1;
                }
            }
        }
    }
    return mf[dst] > 0;
}

void EK(int &flow, int &flow_cost){
    while(spfa()){
        for (int v = dst, i = prec[dst]; v != src; v = vex[i ^ 1], i = prec[v]){
            wgt[i] -= mf[dst];
            wgt[i ^ 1] += mf[dst];
        }
        flow += mf[dst];
        flow_cost += mf[dst] * cost[dst];
    }
}


int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d %d %d %d", &n, &m, &src, &dst);
    for (int i = 0; i < m; i++){
        scanf("%d %d %d %d", &a, &b, &w, &c);
        add_edge(a, b, w, c);
        add_edge(b, a, 0, -c);
    }
    int flow = 0, flow_cost = 0;
    EK(flow, flow_cost);
    printf("%d %d\n", flow, flow_cost);
    return 0;
}