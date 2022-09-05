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


typedef long long llong;
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

Edge edges[MAXN];
int n, m, k, a, b, w, ft[MAXN];

int find(int x) {
    return x != ft[x] ? (ft[x] = find(ft[x])) : ft[x];
}

int kruskal(int k){
    sort(edges + 1, edges + m + 1, [](const Edge& e1, const Edge& e2) {
        return e1.w > e2.w;
    });
    int a, b, mst = 0, cnt = 0;
    for (int i = 1; i <= m; i++) {
        a = find(edges[i].a), b = find(edges[i].b);
        if(a != b){
            ft[a] = ft[b];
            mst += edges[i].w;
            cnt += 1;
        }
        if (cnt == k) break;
    }
    return mst;
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        ft[i] = i;
    for (int i = 1; i <= m; i++){
        scanf("%d %d %d", &a, &b, &w);
        edges[i] = {a, b, w};
    }
    printf("%d\n", kruskal(k));

    return 0;
}