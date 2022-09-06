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


typedef long long llong;
typedef unsigned long long ull;
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
#define  fi    first
#define  se    second
#define  MAXN  100005

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


void kruskal() {
    int cnt = 0, ans = 0;
    for (int i = 0; i < m; i++) {
        int ar = find(edges[i].a), br = find(edges[i].b);
        if(ar == br) continue;
        for (int j = i + 1; j < m; j++){
            if(edges[j].w == edges[i].w){
                int cr = find(edges[j].a), dr = find(edges[j].b);
                // printf("ar = %d, br = %d, cr = %d, dr = %d\n", ar, br, cr, dr);
                if ((ar == cr && br == dr) || (ar == dr && br == cr)) {
                    cout << "Not Unique!" << endl;
                    return;
                }
            }
        }
        ft[ar] = ft[br];
        cnt += 1;
        ans += edges[i].w;
    }
    cout << ans << endl;
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    cin >> kase;
    while(kase--){
        cin >> n >> m;
        for (int i = 0; i < m; i++){
            cin >> a >> b >> w;
            edges[i].a = a;
            edges[i].b = b;
            edges[i].w = w;
        }
        // POJ 似乎并不支持这种过于高级的写法
        // sort(edges, edges + m, [](const Edge & e1, const Edge &e2){
        //     return e1.w  < e2.w;
        // });
        sort(edges, edges + m);

        for (int i = 1; i <= n; i++)
            ft[i] = i;
        kruskal();
    }
    return 0;
}

// 这种做法虽然能够通过，但是过于暴力，
// 本题顶点较少，但是连边数量可以达到 n(n-1)/2 一旦数据量较大便会TLE