#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

typedef long long llong;
typedef unsigned long long ull;

#define  MAXN  100005

vector<int> edges[MAXN];
int d1[MAXN], d2[MAXN], d = 0;

void dfs(int u, int father) {
    d1[u] = d2[u] = 0;
    for (int v : edges[u]) {
        if(v == father)
            continue;
        dfs(v, u);
        int t = d1[v] + 1;
        if(t > d1[u]){
            d2[u] = d1[u], d1[u] = t;
        }else if(t > d2[u]){
            d2[u] = t;
        }
        d = max(d, d1[u] + d2[u]);
    }
}

int kase;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, a, b;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(1, 0);
    printf("%d\n", d);
    return 0;
}