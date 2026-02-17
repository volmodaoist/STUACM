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
typedef pair<ill, int> ii;
typedef unsigned long long ull;
#define  MAXN  500005

int n, m, a, b;
vector<ii> edges[MAXN];
ill f[MAXN], ff[MAXN], dist[MAXN], w, hp;

bool dijstra(int s, int t, ill max_cost) {
    if(f[s] > max_cost || f[s] > max_cost){
        return false;
    }
    priority_queue<ii, vector<ii>, greater<ii>> q;
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    q.emplace(0, s);
    while(q.size()){
        auto [d, u] = q.top(); q.pop();
        if(dist[u] < d){
            continue;
        }
        for(auto [w, v]: edges[u]){
            if(f[v] <= max_cost){
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    q.emplace(dist[v], v);
                }
            }
        }
    }
    return dist[t] <= hp;
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d %d %lld", &n, &m, &hp);
    for (int i = 1; i <= n; i++){
        scanf("%lld", &f[i]);
        ff[i] = f[i];
    }
    sort(ff + 1, ff + 1 + n);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %lld", &a, &b, &w);
        edges[a].emplace_back(w, b);
        edges[b].emplace_back(w, a);
    }
    int lo = 1, hi = n;
    while(lo < hi){
        int md = (lo + hi) / 2;
        if(dijstra(1, n, ff[md])){
            hi = md;
        }else{
            lo = md + 1;
        }
    }
    
    if(dijstra(1, n, ff[lo])){
        printf("%lld\n", ff[lo]);
    }else{
        printf("AFK\n");
    }
    return 0;
}