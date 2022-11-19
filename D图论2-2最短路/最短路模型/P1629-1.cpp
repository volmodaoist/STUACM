#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
#define  MAXN  1005

int n, m, a, b, w;
int g[MAXN][MAXN];

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d %d", &n, &m);
    memset(g, 0x3f, sizeof(g));
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &w);
        g[a][b] = min(g[a][b], w);
    }
    for (int k = 1; k <= n; k++){
        g[k][k] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        ans += g[1][i] + g[i][1];
    }
    printf("%d\n", ans);
    return 0;
}