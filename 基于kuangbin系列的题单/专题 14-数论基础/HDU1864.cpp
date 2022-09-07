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
#define  MAXN  1005

bool sg[MAXN];

int kase;
int main() {
#ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, m;
    scanf("%d", &kase);
    while(kase--){
        scanf("%d %d", &n, &m);
        memset(sg, 0, sizeof(sg));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++){
                if(!sg[i - j]){
                    sg[i] = true;
                    break;
                }
            }
        }
        // 本题实际是一个巴什博奕问题，代码其实能写为 n % (m + 1)
        printf("%s\n", sg[n] ? "first" : "second");
    }
    return 0;
}