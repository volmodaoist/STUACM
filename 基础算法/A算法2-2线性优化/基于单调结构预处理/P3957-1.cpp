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
#define  MAXN  500005

ill dp[MAXN];
int n, d, k, x[MAXN], s[MAXN], ans;

bool check(int lo, int hi){
    dp[0] = 0LL;
    for (int i = 1; i <= n; i++){
        dp[i] = -2e9;
        for (int j = 0; j < i; j++){
            if(x[i] - x[j] > hi) continue;
            if(x[i] - x[j] < lo) break;
            if (x[i] - x[j] >= lo && x[i] - x[j] <= hi) {
                dp[i] = max(dp[i], dp[j] + s[i]);
            }
        }
        if(dp[i] >= k) return true;
    }
    return false;
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    ill tot = 0;
    int lo = 0, hi = 0;
    scanf("%d %d %d", &n, &d, &k);
    for (int i = 1; i <= n; i++){
        scanf("%d %d", &x[i], &s[i]);
        hi = max(hi, x[i]);
        tot += (s[i] > 0 ? s[i] : 0);
    }
    if(tot < k){
        printf("-1\n");
    }else{
        while(lo < hi){
            int md = lo + (hi - lo) / 2;
            if(check(max(1, d - md), d + md)){
                hi = md;
                ans = md;
            } else {
                lo = md + 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}