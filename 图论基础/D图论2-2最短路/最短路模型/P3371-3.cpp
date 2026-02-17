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
#define MAXN 100005

int a, b, w, n, m, s;
vector<ii> edges[MAXN];
int vist[MAXN], dist[MAXN];

bool bellman_ford(int s) {
    bool is_updated;
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    for (int i = 1; i <= n; i++) {
        is_updated = false;
        for (int u = 1; u <= n; u++) {
            if (dist[u] == 0x3f3f3f3f)
                continue;
            for (auto [w, v] : edges[u]) {
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    is_updated = true;
                }
            }
        }
        if(!is_updated) break;
    }
    return is_updated;
}


int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &w);
        edges[a].emplace_back(w, b);
    }
    bellman_ford(s);
    for (int i = 1; i <= n; i++){
        if(dist[i] != 0x3f3f3f3f){
            printf("%d ", dist[i]);
        }else{
            printf("%d ", INT_MAX);
        }
    }
    printf("\n");
    return 0;
}