#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	CLEAR(A,x)  (memset(A,x,sizeof(A)))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <limits>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
#define  MAXN  500005

typedef struct _Trash{
    int t, f, h;
    bool operator<(const struct _Trash& other) const{
        if (t != other.t) {
            return t < other.t;
        }else if(h != other.h){
            return h > other.h;
        }else{
            return f > other.f;
        }
    }
} Trash;

ill dp[MAXN];
Trash ts[MAXN];

void debug_print_input(int n){
    for (int i = 1; i <= n; i++){
        printf("%d %d %d\n", ts[i].t, ts[i].f, ts[i].h);
    }
    printf("\n");
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int d, g, t, f, h, s;
    scanf("%d %d", &d, &g);
    scanf("%d", &s);
    for (int i = 1; i <= g; i++) {
        scanf("%d %d %d", &t, &f, &h);
        ts[i] = {t, f, h};
    }

    sort(ts + 1, ts + 1 + g);
    // debug_print_input(g);

    memset(dp, 0xcf, sizeof(dp));
    dp[0] = s;
    for (int i = 1; i <= g; i++) {
        for (int j = d; j >= 0; j--){
            if(dp[j] < ts[i].t)
                continue;
            if(j + ts[i].h >= d){
                printf("%d\n", ts[i].t);
                return 0;
            }
            dp[j + ts[i].h] = max(dp[j + ts[i].h], dp[j]);
            dp[j] += ts[i].f;
        }    
    }
    printf("-1\n");
    printf("%lld\n", dp[0]);
    return 0;
}


