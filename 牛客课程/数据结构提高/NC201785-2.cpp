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


typedef long long llong;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
#define  MAXN  100005


// 使用 ones 记录 ith 元素 前面数字 1 个数,
// 使用 prev 记录 ith 元素 前驱数组 1 所在的索引，

int v[MAXN], ones[MAXN], prec[MAXN];
llong dp[MAXN];

/**
 *   使用 dp 记录 ith 元素 能够产生的 link 能量,  假设 i-1 th 元素产生的能量记作 x，再把 i-1th 与 ith 之间间隔记作 d，
 * 能为 i-1 th 元素贡献能量的数字 1，亦为 ith 贡献能力，并且比起x，每个数字都会额外多贡献 d，也就是说，我们需要知道，
 * 上一个状态产生能量是多少，以及 ith 元素前面共有多少 1，然后补上 i-1th 与 ith 之间产生的能量即可
*/

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%1d", &v[i]);
    }


    for (int i = 1; i <= n; i++) {
        prec[i] = prec[i - 1], ones[i] = ones[i - 1];
        if (v[i]) {
            dp[i] = (dp[prec[i]] + ones[i] * (i - prec[i])) % MOD;
            prec[i] = i;
            ones[i]++;
        }
    }
    

    llong ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[i]) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}