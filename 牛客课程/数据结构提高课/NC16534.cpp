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

int block[MAXN];

int solve(int lo, int hi, int s){
    if(lo > hi) return 0;
    if (lo == hi) return block[lo] - s;
    int ans = 0, idx = lo;
    
    // 此处的最小值查询能用稀疏表预处理
    for (int i = lo; i <= hi; i++) {
        if(block[idx] > block[i]){
            idx = i;
        }
    }
    ans += block[idx] - s;
    ans += solve(lo, idx - 1, block[idx]);
    ans += solve(idx + 1, hi, block[idx]);
    return ans;
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &block[i]);
    }
    printf("%d\n", solve(1, n, 0));
    return 0;
}