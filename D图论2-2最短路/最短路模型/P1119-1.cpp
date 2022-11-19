#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
typedef pair<int, int> ii;
#define MAXN 500

int n, m, a, b, w, q;
int days[MAXN], dist[MAXN], vist[MAXN];
vector<ii> edges[MAXN];

// 带上备忘录优化也是无法通过的
map<ull, int> ans;

int dijstra(int src, int dst, int now){
    if(days[src] > now || days[dst] > now){
        return -1;
    }
    ull code = (src * 1000 + dst) * 1000000 + now;
    if(ans.count(code)){
        return ans[code];
    }
    memset(dist, 0x3f, sizeof(dist));
    memset(vist, 0, sizeof(vist));
    dist[src] = 0;
    for (int i = 1; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++){
            if (!vist[j] && (u == -1 || dist[u] > dist[j])) {
                u = j;
            }
        }
        if(u == -1) break;
        vist[u] = 1;
        for (auto [w, v] : edges[u]) {
            if(days[v] <= now){
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
    if(dist[dst] == 0x3f3f3f3f){
        ans[code] = -1;
        return -1;
    } else {
        ans[code] = dist[dst];
        return dist[dst];
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++){
        scanf("%d", &days[i]);
    }
    for (int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &w);
        edges[a].emplace_back(w, b);
        edges[b].emplace_back(w, a);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++){
        scanf("%d %d %d", &a, &b, &w);
        printf("%d\n", dijstra(a, b, w));
    }
    return 0;
}