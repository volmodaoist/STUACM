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
#define MAXN 3005

int n, m, a, b, w;
vector<ii> edges[MAXN];
int dist[MAXN], vist[MAXN];

void dijstra(int s){
    memset(dist, 0x3f, sizeof(dist));
    memset(vist, 0, sizeof(vist));
    priority_queue<ii, vector<ii>, greater<ii>> q;
    dist[s] = 0;
    q.push({0, s});
    while(q.size()){
        auto [_, u] = q.top(); q.pop(); 
        if(vist[u]){
            continue;
        }
        vist[u] = 1;
        for (auto [w, v] : edges[u]) {
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                q.emplace(dist[v], v);
            }
        }
    }
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &w);
        edges[a].emplace_back(w, b);
        edges[b + n].emplace_back(w, a + n);
    }
    int ans = 0;
    dijstra(1);
    for (int i = 1; i <= n; i++) {
        ans += dist[i];
    }
    dijstra(1 + n);
    for (int i = 1 + n; i <= 2 * n; i++){
        ans += dist[i];
    }
    printf("%d\n", ans);
    return 0;
}