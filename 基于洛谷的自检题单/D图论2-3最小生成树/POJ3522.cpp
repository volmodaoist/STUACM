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


#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
#define  fi    first
#define  se    second
#define  MAXN  100005

// 本题要求生成树，且打印最小极差，但是生成树本身但不一定要最小的，
// 按照从小到大或是从大到小都不影响其计算最大极差，
typedef struct _Edge{
    int a, b, w;
    bool operator <(const struct _Edge &other) const{
        return w < other.w;
    }
} Edge;


Edge edges[MAXN];

int ft[MAXN];
int n, m, a, b, w , kase;

int find(int x){
    return x != ft[x] ? (ft[x] = find(ft[x])) : x;
}

int kruskal(int idx, int &gloabl_counter) {
    for (int i = 1; i <= n; i++)
        ft[i] = i;
    int mst = 0, minv = INT_MAX, maxv = INT_MIN;
    for (int i = idx; i < m; i++) {
        int ar = find(edges[i].a), br = find(edges[i].b);
        if(ar != br){
            ft[ar] = ft[br];
            minv = min(minv, edges[i].w);
            maxv = max(maxv, edges[i].w);
            gloabl_counter++;
            mst += edges[i].w;
            if (gloabl_counter == n - 1) break;
        }
    }
    // 需要特判，不然INT_MAX - INT_MIN 是会出错的！
    return (gloabl_counter == n - 1) ? (maxv - minv) : INT_MAX;
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    while (cin >> n >> m) {
        // printf("Test(n = %d,  m = %d)\n", n, m);
        if (n == 0 && m == 0)
            break;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> w;
            edges[i].a = a;
            edges[i].b = b;
            edges[i].w = w;
        }
        sort(edges, edges + m);

        // 先看看有没有可能构成生成树
        int gloabl_counter = 0;
        int ans = kruskal(0, gloabl_counter);

        // 如果全部边集都用上也无法形成生成树则不用再考虑了
        if (gloabl_counter < n - 1){
            cout << -1 << endl;
        }else{
            // 能够构成生成树的情况之下再考虑减少边集构建生成树, 
            for (int i = 1; i < m; i++) {
                gloabl_counter = 0;
                ans = min(ans, kruskal(i, gloabl_counter));
            }
            cout << ans << endl;
        }
    }
    return 0;
}