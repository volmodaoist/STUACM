#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	CLEAR(A,x)  (memset(A,x,sizeof(A)))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <limits>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
#define  fi    first
#define  se    second
#define  MAXN  500005

typedef struct Edge{
    int a, b, w;
} Edge;
vector<Edge> edges;

int n, m, a, b, w, ft[MAXN], pt[MAXN], best[MAXN];
int find(int x) {
    return x != ft[x] ? (ft[x] = find(ft[x])) : x;
}
int boruvka(){
    int ans = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
        ft[i] = i;
    while (1) {
        // 每轮循环都要记得把所有连通分量当前最小边设为无穷大
        int no_update = 1;
        memset(best, 0x3f, sizeof(best));

        // 遍历边集合，使用连边的端点更新每个连通块连着的最小边
        for (int i = 0; i < edges.size(); i++){
            int ar = find(edges[i].a), br = find(edges[i].b), w = edges[i].w;
            if(ar == br) continue;
            if(w < best[ar]) best[ar] = w, pt[ar] = br;
            if(w < best[br]) best[br] = w, pt[br] = ar;
            // 这种做法存储最小连边的权值，由于丢失连边的编号，所以另外一个数组pt,
            // pt 记录这条连边用于连接哪两个连通分量, 如果best记录连边的编号也就不用另外开一个pt (point to) 数组了!
        }
    
        // 遍历所有连通块，根据最小边合并连通块
        for (int i = 1; i <= n; i++){
            if (best[i] < INF && find(i) != find(pt[i])) {
                cnt++;
                ans += best[i], no_update = 0;
                ft[find(i)] = ft[find(pt[i])];
            }
        }
        if(no_update) break;
    }
    return cnt == n - 1 ? ans : -INF;
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &w);
        edges.push_back({a, b, w});
    }
    int t = boruvka();
    if(t != -INF){
        printf("%d\n", t);
    }else{
        printf("orz\n");
    }
    return 0;
}