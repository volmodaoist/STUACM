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
#include <limits.h>
using namespace std;


typedef long long llong;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
#define  MAXN  1000

// int mt[MAXN][MAXN];
// https://codeforces.com/contest/577/problem/A

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    int n, x;
    scanf("%d %d", &n, &x);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if ((x % i == 0) && (x / i <= n)) {
            ans ++;
        }
    }
    printf("%d\n", ans);

    return 0;
}