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


typedef long long LLong;
typedef unsigned long long ULL;
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
int n, m, a, b, c, pt[MAXN];

int find(int x){
    return (x != pt[x]) ? (pt[x] = find(pt[x])) : x;
}

int main() {
#ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        pt[i] = i;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        edges[i] = {a, b, c};
    }
    sort(edges, edges + m, [](const Edge &a, const Edge &b){
        return a.w < b.w;
    });
    int cnt = 0, ans = 0;
    for (int i = 0; i < m; i++) {
        int ar = find(edges[i].a);
        int br = find(edges[i].b);
        if(ar != br){
            pt[ar] = pt[br];
            cnt++;
            ans += edges[i].w;
        }
        if (cnt == n - 1)break;
    }
    if(cnt == n - 1){
        printf("%d\n", ans);
    }else {
        printf("orz\n");
    }
    return 0;
}