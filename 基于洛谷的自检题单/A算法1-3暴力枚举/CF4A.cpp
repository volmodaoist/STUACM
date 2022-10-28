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


int kase;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif



        
    /**
     * 能否分割w，使得 w = a + b，并且 a + b 都是偶数，a 与 b 不强制要求相等，
     * 如果 a 与 b 必须相等于，那么本题只需要判定 w 是不是 4 整数倍数即可，
    */

    int w;
    scanf("%d", &w);
    bool ok = false;
    for (int i = 2; i <= w; i += 2) {
        int j = w - i;
        if (j && (~i & 1) && (~j & 1)) { 
            ok = true;
            break;
        }
        // i与j 均为偶数且不等于0
    }

    printf("%s\n", ok ? "YES" : "NO");
    return 0;
}