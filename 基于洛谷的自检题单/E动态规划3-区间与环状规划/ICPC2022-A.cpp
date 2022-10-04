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
#define  fi    first
#define  se    second
#define  MAXN  1000005

char str[MAXN];
int prec[MAXN], last[MAXN], nc[MAXN];  //存储非连续1个数


// 本题来自于 ICPC 2022 网络赛 区域赛预选赛
int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    int n, m, a, b, cnt = 0;
    scanf("%d %d", &n, &m);
    scanf("%s", str + 1);

    cnt = 0;
    for (int i = 1; i <= n; i++) {
        if(str[i] == '1'){
            cnt++;
        }else{
            cnt = 0;
        }
        prec[i] = cnt;
    }

    cnt = 0;
    for (int i = n; i >= 1; i--) {
        if(str[i] == '1'){
            cnt++;
        }else{
            cnt = 0;
        }
        last[i] = cnt;
    }

    cnt = 0;
    for (int i = 1; i <= n; i++) {
        if(str[i] == '1'){
            cnt++;
        }else{
            cnt = 0;
        }
        nc[i] = ((i - cnt - 1 >= 0) ? nc[i - cnt - 1] : 0) + (cnt + 1) / 2;
    }

    while(m--){
        scanf("%d %d", &a, &b);
        int pb = prec[b];
        int la = last[a];
        int cycle_one = (pb + la + 1) / 2;
        int elim = nc[b - pb] - nc[a + la] + cycle_one;
        if (((b - a + 1) / 3) <= elim) {
            printf("0\n");
        } else {
            printf("%d\n", ((b - a + 1) / 3) - elim);
        }
    }
    return 0;
}