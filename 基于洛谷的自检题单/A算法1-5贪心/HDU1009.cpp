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


typedef long long llong;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
#define  MAXN  100005

typedef struct _Room{
    int j, f;
    bool operator<(const struct _Room& other) const{
        double one = 1.000;
        return (one * j / f) > (one * other.j / other.f);
    }
} Room;

Room rooms[MAXN];

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, m;
    while (scanf("%d %d", &m, &n)) {
        if(m == -1 && n == -1)
            break;

        
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &rooms[i].j, &rooms[i].f);
        }

        // 按照性价比排序是一个非常直观的想法
        sort(rooms, rooms + n);

        // 需要注意此处的浮点精度控制，如果不乘以 one 会导致精度出错
        double ans = 0, one = 1.0000;
        for (int i = 0; i < n; i++) {
            if(m >= rooms[i].f){
                ans += rooms[i].j;
                m -= rooms[i].f;
            } else {
                ans += (one * rooms[i].j / rooms[i].f * m);
                m = 0;
                break;
            }
        }
        printf("%.3lf\n", ans);
    }

    return 0;
}