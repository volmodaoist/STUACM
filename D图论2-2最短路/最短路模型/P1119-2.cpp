#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long ill;
typedef pair<int, int> ii;
#define MAXN 500

int n, m, a, b, w, q;
int days[MAXN], dist[MAXN], vist[MAXN];
int g[MAXN][MAXN];

void update(int k){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
    }
}


int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++){
        scanf("%d", &days[i]);
    }
    memset(g, 0x3f, sizeof(g));
    for (int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &w);
        g[a][b] = g[b][a] = w;
    }
    scanf("%d", &q);

    int now = 0;
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &a, &b, &w);
        while(now < n && days[now] <= w){
            update(now);
            now++;
        }
        if (days[a] > w || days[b] > w || g[a][b] == 0x3f3f3f3f ){
            printf("-1\n");
        }else{
            printf("%d\n", g[a][b]);
        }
    }
    return 0;
}