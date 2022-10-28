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
#define  MAXN  300005


int n;
ill nums[MAXN];
ill prefix[MAXN];
int deq[MAXN], head, tail = -1;


int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &nums[i]);
        prefix[i] = prefix[i - 1] + nums[i];
    }
    
    deq[++tail] = 0;
    ill ans = -2e9;
    for (int i = 1; i <= n; i++) {
        while(head <= tail && prefix[i] <= prefix[deq[tail]]){
            --tail;
        }
        ans = max(ans, prefix[i] - prefix[deq[head]]);
        deq[++tail] = i;
    }
    printf("%lld\n", ans);
    return 0;
}