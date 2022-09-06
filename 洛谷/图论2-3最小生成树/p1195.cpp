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
#define  MAXN  100005

typedef struct Edge{
    int a, b, w;
} Edge;

vector<iii> edges;
int n, m, k, a, b, w;
int ft[MAXN];

int find(int x){
    return ft[x] != x ? (ft[x] = find(ft[x])) : x;
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &w);
        edges.emplace_back(w, a, b);
    }
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= n; i++)
        ft[i] = i;
    int cnt = 0, ans = 0;
    for (int i = 0; i < edges.size(); i++) {
        int w = get<0>(edges[i]), a = get<1>(edges[i]), b = get<2>(edges[i]);
        if(find(a) != find(b)){
            ft[find(a)] = ft[find(b)];
            ans += w;
            cnt++;
        }
        if(cnt == n - k) break;
    }
    printf("%d\n", ans);
    return 0;
}