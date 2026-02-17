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
ill p[MAXN], q[MAXN], total;

ill max_two_sum(ill *nums, int n){
    f[1] = nums[1];
    for (int i = 2; i <= n; i++) {
        f[i] = max(f[i - 1] + nums[i], nums[i]);
    }
    for (int i = 2; i <= n; i++) {
        f[i] = max(f[i - 1], f[i]);
    }

    g[n] = nums[n];
    for (int i = n - 1; i > 0; i--) {
        g[i] = max(g[i + 1] + nums[i], nums[i]);
    }
    for (int i = n - 1; i > 0; i--) {
        g[i] = max(g[i + 1], g[i]);
    }

    ill maxv = INT_MIN;
    for (int i = 1; i < n; i++) {
        maxv = max(maxv, f[i] + g[i + 1]);
    }
    return maxv;
}


ill min_two_sum(ill *nums, int n){
    p[1] = nums[1];
    for (int i = 2; i <= n; i++) {
        p[i] = min(p[i - 1] + nums[i], nums[i]);
    }
    for (int i = 2; i <= n; i++) {
        p[i] = min(p[i - 1], p[i]);
    }

    q[n] = nums[n];
    for (int i = n - 1; i > 0; i--) {
        q[i] = min(q[i + 1] + nums[i], nums[i]);
    }
    for (int i = n - 1; i > 0; i--) {
        q[i] = min(q[i + 1], q[i]);
    }

    ill minv = INT_MAX;
    for (int i = 2; i < n; i++) {
        minv = min(minv, p[i - 1] + q[i + 1]);
    }
    return minv;
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    // 维护两个最大子段和f、g，一个是以A[i]结尾的最大子段和，另一个是以A[i]开头的最大子段和
    // 维护两个最小子段和p、q，一个是以A[i]结尾的最小子段和，另一个是以A[i]开头的最小子段和
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &nums[i]);
        total += nums[i];
    }

    // 直接取最大，掐头去尾取最小，然后再做比较
    ill ans = INT_MIN;
    ans = max(ans, max_two_sum(nums, n));

    /**
     * 为什么需要掐头去尾呢? 
     * 这是因为如果选出来的两个最小子段是整个序列减掉一个元素，使用x代表选出来的最小子段和
     * 如果出现这种情况， xxxx 0 xxxx， 此时只有一个元素在中间了，然而两条最大子段和元素个数至少等于 2
    */ 
    ans = max(ans, total - min_two_sum(nums + 1, n - 1));
    ans = max(ans, total - min_two_sum(nums, n - 1));
    printf("%lld\n", ans);

    return 0;
}