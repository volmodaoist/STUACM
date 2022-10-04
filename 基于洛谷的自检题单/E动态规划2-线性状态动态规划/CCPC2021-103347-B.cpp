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


// https://codeforces.com/gym/103447/problem/B

/** 由于 Ai 数值范围很小，因而能够枚举所有可能的两数之和搜索可能构成的序列的最大长度，
 *  本题来自CCPC 2021 哈尔滨站 第 B 题 「Magical Subsequence」，需要注意的几个细节:
 *   
 *    (1) 使用 prec 数组记录上一个 v[i] 元素出现的位置，
 *    
 *    (2) 状态转移的时候，前一个状态应为 prec[target - v[i]] - 1，而非 prec[target - v[i]]，
 *  后者已与 ith 构成了数对， 如果使用 prec[target - v[i]] 会导致状态被重复计算
 *    
 *    (3) 状态转移方程切勿写成 dp[i] =  dp[prec[target - v[i]] - 1] + 2，因为 dp[i]直接转移于
 *  前一个 i-1th 状态，这个状态说不定比起逻辑上面的「前一个」状态 (prec[target - v[i]] - 1)th 结果更大，
 *   
 */


int prec[MAXN], n, v[MAXN], dp[MAXN];
int solve(int target) {
    for (int i = 1; i <= n; i++)
        prec[i] = 0, dp[i] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if (v[i] < target && prec[target - v[i]]) {
            dp[i] = max(dp[i], dp[prec[target - v[i]] - 1] + 2);
        }
        prec[v[i]] = i;
    }
    return dp[n];
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    int ans = 0;
    for (int i = 2; i <= 200; i++) {
        ans = max(ans, solve(i));
    }
    printf("%d\n", ans);
    return 0;
}