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
#define  rc(x)  (x<<1|1)g
#define  fi    first
#define  se    second
#define  MAXN  500005

typedef struct Edge{
    int a, b, w;
} Edge;
vector<Edge> edges;

/**
 * 数组best记录了当前连通块与外部的最小连边
 * 一旦合并了两个连通分类，与外部最小连边也就内化了，故每趟循环都要重置best数组
 */ 
int n, m, a, b, w, ft[MAXN], best[MAXN];
int find(int x) {
    return x != ft[x] ? (ft[x] = find(ft[x])) : x;
}

// 使用best 记录连边的编号，而非最小连边的边权的
int boruvka(){
    int ans = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
        ft[i] = i;
    while (1) {
        // 每轮循环都要记得把所有连通分量当前最小边设为无穷大
        int no_update = 1;
        memset(best, -1, sizeof(best));

        // 遍历边集合，使用连边的端点更新每个连通块连着的最小边
        for (int i = 0; i < edges.size(); i++){
            int ar = find(edges[i].a), br = find(edges[i].b), w = edges[i].w;
            if(ar == br) continue;
            if (best[ar] == -1 || w < edges[best[ar]].w) best[ar] = i;
            if (best[br] == -1 || w < edges[best[br]].w) best[br] = i;
        }

        // 遍历所有连通块，根据最小边合并连通块
        for (int i = 1; i <= n; i++){
            if(best[i] == -1)
                continue;
            // 不添加这条判断, 下面edges数组访问会出现越界
            int ar = find(edges[best[i]].a), br = find(edges[best[i]].b);
            if (ar != br) {
                ans += edges[best[i]].w;
                ft[ar] = ft[br];
                no_update = 0;
                cnt++;
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