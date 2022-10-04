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

int road[MAXN];

int solve(int lo, int hi, int s){
    if(lo > hi) return 0;
    if (lo == hi) return road[lo] - s;
    int ans = 0, idx = lo;
    for (int i = lo; i <= hi; i++) {
        if(road[idx] > road[i]){
            idx = i;
        }
    }
    ans += road[idx] - s;
    ans += solve(lo, idx - 1, road[idx]);
    ans += solve(idx + 1, hi, road[idx]);
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
        scanf("%d", &road[i]);
    }
    printf("%d\n", solve(1, n, 0));
    return 0;
}