#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
#define  MAXN  2000000


// 由于数据都是非负数，直接滑动窗口就好
int n, k;
ill dp[MAXN][2];
ill p[MAXN], s[MAXN];
int deq[MAXN], head, tail = 0;

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &p[i]);
        s[i] = s[i - 1] + p[i];
    }

    deq[++tail] = 0;
    for (int i = 1; i <= n; i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        while (head <= tail && i - deq[head] > k) {
            head++;
        }
        dp[i][1] = dp[deq[head]][0] - s[deq[head]] + s[i];
        while (head <= tail && dp[i][0] - s[i] > dp[deq[tail]][0] - s[deq[tail]]) {
            tail--;
        }
        deq[++tail] = i;
    }
    printf("%lld\n", max(dp[n][1], dp[n][0]));
    return 0;
}