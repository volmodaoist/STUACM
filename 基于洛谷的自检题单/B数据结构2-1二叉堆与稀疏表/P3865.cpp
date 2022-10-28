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
#include <limits.h>
using namespace std;


#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  MAXN  1000005

int v[MAXN], st[MAXN][30], lb[MAXN];
int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, m, a, b, s;
    scanf("%d %d", &n, &m);
    lb[1] = 0;
    for (int i = 2; i <= n; i++) {
        lb[i] = lb[i >> 1] + 1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        st[i][0] = v[i];
    }
    // 左闭右开区间 [i, i + 2^(j-1)) 与 [i + 2^(j-1), i + 2^(j)]
    for (int j = 1; j <= 30; j++){
        for (int i = 0; i + (1 << j) - 1 < n; i++){
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    // 本题给定的序列区1-base 间端，我们使用 0-base 端点
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        b--, a--;
        s = lb[b - a + 1];
        printf("%d\n", max(st[a][s], st[b - (1 << s) + 1][s]));
    }

    return 0;
}