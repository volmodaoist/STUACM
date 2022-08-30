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


typedef long long LLong;
typedef unsigned long long ULL;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
#define  fi    first
#define  se    second
#define  MAXN  105

int n, a, b;
bool g[MAXN][MAXN];

void floyd(){
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                g[i][j] |= (g[i][k] && g[k][j]);
            }
        }
    }
}

void debug_check_graph(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            printf("%d ", g[i][j] == INF ? 0 : g[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d", &n);
    for (int i = 1; i < n; i++){
        scanf("%d %d", &a, &b);
        g[a][b] = true;
    }
    floyd();
    int ans = -1;
    for (int i = 1; i <= n; i++){
        int t = 0;
        for (int j = 1; j <= n; j++) {
            if(g[j][i]){
                t++;
            }
        }
        if(t == n - 1){
            ans = i;
            break;
        }
    }
    printf("%d\n", ans);

    return 0;
}