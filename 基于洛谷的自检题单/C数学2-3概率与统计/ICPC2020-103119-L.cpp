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


// 本题来自于亚洲区域赛 https://codeforces.com/gym/103119/problem/L
// 问你随机生成一个整数序列 {ai}，每个元素都在1~n, 要求计算排列1~n数字的全排列{pi}，问你满足pi<=ai情况的期望
// 本题很容易列出式子 (n! * n!) / (n^n), 难点在于大数的处理，一种比较取巧的方法是用Python，另外一种方法是用 long double 类型

int kase;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n;
    long double ans = 1.0;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        ans = (ans * i * i) / n;
    }
    printf("%.15Lf\n", ans);

    return 0;
}