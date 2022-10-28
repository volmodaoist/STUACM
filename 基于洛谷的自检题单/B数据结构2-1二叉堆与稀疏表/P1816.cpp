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


#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
#define  MAXN  100005

int v[MAXN], lb[MAXN], st[MAXN][30];
int main() {
#ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, m, a, b;
    scanf("%d %d", &n, &m);
    lb[1] = 0;
    for (int i = 2; i <= n; i++){
        lb[i] = lb[i >> 1] + 1;
    }
    memset(st, 0x3f, sizeof(st));
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        st[i][0] = v[i];
    }

    for (int j = 1; j <= 30; j++){
        for (int i = 1; i + (1 << j) - 1 <= n; i++){
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    while(m--){
        scanf("%d %d", &a, &b);
        int s = lb[b - a + 1];
        printf("%d ", min(st[a][s], st[b - (1 << s) + 1][s]));
    }
    printf("\n");
    return 0;
}