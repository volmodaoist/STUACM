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
typedef unsigned long long ULL;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
#define  fi    first
#define  se    second
#define  MAXN  1005

typedef struct Point{
    int x, y;
} Point;


Point p[MAXN];
bool v[MAXN];
double g[MAXN][MAXN], d[MAXN];
double dist(Point& a, Point& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}


int n, m, a, b, x, y;
double prim(int src){
    double ans = 0;
    memset(d, 0x7f, sizeof(d));
    d[src] = 0;
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!v[j] && (t == -1 || d[t] > d[j])) {
                t = j;
            }
        }

        v[t] = 1;
        ans += d[t];
        for (int j = 1; j <= n; j++) {
            if(!v[j] && d[j] > g[t][j]){
                d[j] = g[t][j];
            }
        }

    }
    return ans;
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d %d ", &n, &m);
    memset(g, 0x7f, sizeof(g));
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x, &y);
        p[i] = {x, y};
    }
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            g[i][j] = g[j][i] = dist(p[i], p[j]);
        }
    }

    for (int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        g[a][b] = g[b][a] = 0;
    }

    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < n; j++){
    //         printf("%.2lf ", g[i][j] > INF ? -1 : g[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("%.2lf\n", prim(1));

    return 0;
}