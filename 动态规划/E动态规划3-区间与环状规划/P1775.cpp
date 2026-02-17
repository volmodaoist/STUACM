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

#define  MAXN  305

int n, x[MAXN], s[MAXN], f[MAXN][MAXN];
int main() {
#ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d", &n);
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
    }
    for (int i = 1; i <= n; i++) {
        f[i][i] = 0;
        s[i] = s[i - 1] + x[i];
    }
    for (int len = 1; len <= n; len++){         // Phase
        for (int i = 0; i + len - 1 <= n; i++){ // State
            int j = i + len - 1;                // State
            for (int k = i; k < j; k++){        // Decision
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }
    printf("%d\n", f[1][n]);
    return 0;
}