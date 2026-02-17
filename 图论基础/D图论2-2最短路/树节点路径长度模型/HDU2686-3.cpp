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
#define  MAXN  50005

vector<ii> edges[MAXN];
vector<ii> query[MAXN];
bool vist[MAXN];
int ft[MAXN], path[MAXN], vexa[MAXN], vexb[MAXN], ans[MAXN];
int n, q, a, b, w, kase;

int find(int x){
    return ft[x] != x ? (ft[x] = find(ft[x])) : x;
}

void tarjan(int u, int father, int father_weight){
    vist[u] = true;
    path[u] = path[father] + father_weight;
    for(auto &vex_wgt: edges[u]){
        int v = vex_wgt.first, w = vex_wgt.second;
        if(v == father) // 使用 vist 数组来避免重复访问也是等价的
            continue;
        tarjan(v, u, w);
        ft[v] = u;
    }
    for(auto &q: query[u]){
        int v = q.first, i = q.second;
        if(vist[v]){
            ans[i] = find(v);
        }
    }
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d", &kase);
    while(kase--){
        scanf("%d %d", &n, &q);

        // 初始化
        for (int i = 1; i <= n; i++)
            ft[i] = i;
        for (int i = 1; i <= n; i++)
            edges[i].clear();
        for (int i = 0; i < q; i++)
            query[i].clear();

        memset(path, 0, sizeof(path));
        memset(vist, 0, sizeof(vist));
        for (int i = 1; i < n; i++) {
            scanf("%d %d %d", &a, &b, &w);
            edges[a].emplace_back(b, w);
            edges[b].emplace_back(a, w);
        }
        for (int i = 0; i < q; i++) {
            scanf("%d %d", &a, &b);
            vexa[i] = a;
            vexb[i] = b;
            query[a].emplace_back(b, i);
            query[b].emplace_back(a, i);
        }

        // 所有信息读完之后才能调用 tarjan

        tarjan(1, 0, 0); 
        for (int i = 0; i < q; i++){
            printf("%d\n", path[vexa[i]] + path[vexb[i]] - 2 * path[ans[i]]);
        }
        
    }

    return 0;
}