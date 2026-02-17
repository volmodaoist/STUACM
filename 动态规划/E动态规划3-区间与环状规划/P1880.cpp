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


#define MAXN 500
int n, x[MAXN], s[MAXN], f[MAXN][MAXN], g[MAXN][MAXN];

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d", &n);
    memset(g, 0x3f, sizeof(f));
    for(int i = 1; i <= n; i++){
        scanf("%d", &x[i]);
        x[i + n] = x[i];
    }
    for (int i = 1; i <= 2 * n; i++){
        s[i] = s[i - 1] + x[i];
        f[i][i] = g[i][i] = 0;
    }
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i + len - 1 <= 2 * n; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k + 1][j] + s[j] - s[i - 1]);
                f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }
    int minv = 2e9, maxv = -2e9;
    for (int i = 0; i <= n; i++){
        minv = min(minv, g[i][i + n - 1]);
        maxv = max(maxv, f[i][i + n - 1]);
    }
    printf("%d\n%d\n", minv, maxv);
    return 0;
}