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
#define  MAXN  3000005


int n;
ill nums[MAXN];
ill f[MAXN], g[MAXN];

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    // 维护两个子段和，一个是以A[i]结尾的最大子段和，另一个是以A[i]开头的最大子段和
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &nums[i]); 
    }
    
    f[1] = nums[1];
    for (int i = 2; i <= n; i++){
        f[i] = max(f[i - 1] + nums[i], nums[i]);
    }
    for (int i = 2; i <= n; i++) {
        f[i] = max(f[i - 1], f[i]);
    }

    g[n] = nums[n];
    for (int i = n - 1; i > 0; i--) {
        g[i] = max(g[i + 1] + nums[i], nums[i]);
    }
    for (int i = n - 1; i > 0; i--){
        g[i] = max(g[i + 1], g[i]);
    }

    // 第 i 个元素肯定是不选择的，否则会出现重叠，两段将会合成一段
    ill ans = -2e9;
    for (int i = 2; i < n; i++) {
        ans = max(ans, f[i - 1] + g[i + 1]);
    }
    printf("%lld\n", ans);
    return 0;
}