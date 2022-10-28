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

int n, k, kase, arr[MAXN];

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d", &kase);
    while(kase--){
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        llong ans = 0;
        for (int i = 0; i + k <= n; i++) {
            llong sumv = 0;
            for (int h = i; h < i + k; h++) {
                int maxv = arr[h];
                // 右侧寻找当前位置能够交换得到的最大值
                for (int x = 1; h + x * k < n; x++) {
                    if(h + x * k < n){
                        maxv = max(maxv, arr[h + x * k]);
                    }
                }
                // 左侧寻找当前位置能够交换得到的最大值
                for (int x = 1; h - x * k >= 0; x++) {
                    if (h - x * k >= 0){
                        maxv = max(maxv, arr[h - x * k]);
                    }
                }
                sumv += maxv;
            }
            ans = max(ans, sumv);
        }
        printf("%lld\n", ans);
    }
    return 0;
}