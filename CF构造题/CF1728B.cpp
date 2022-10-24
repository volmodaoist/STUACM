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


// https://codeforces.com/contest/1728/problem/B
int kase, n;
int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d", &kase);
    while(kase--){
        scanf("%d", &n);
        if (n & 1){
            // ÆæÊý
            for (int i = n - 1 - 1; i >= 5; i -= 2) {
                printf("%d %d ", i, i - 1);
            }
            for (int i = 1; i <= 3; i++){
                printf("%d ", i);
            }
        }else{
            // Å¼Êý
            for (int i = n - 1 - 1; i >= 2; i -= 2) {
                printf("%d %d ", i, i - 1);
            }
        }
        printf("%d %d\n", n - 1, n);
    }
    return 0;
}