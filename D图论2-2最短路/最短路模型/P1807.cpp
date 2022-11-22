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
#define  MAXN  100005

int n, m, a, b, c, is_cycle, reachable;
int vist[MAXN], dist[MAXN], cot[MAXN], inq[MAXN];
vector<ii> edges[MAXN];

void bellman_ford(int s = 1){
    memset(dist, 0x7f, sizeof(dist));
    dist[1] = 0;
    queue<int> q; q.push(s); inq[s] = 1;
    while (q.size()) {
        int u = q.front(); q.pop(); inq[u] = 0;
        for (auto [w, v] : edges[u]) {
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                cot[v] = cot[u] + 1;
                if(cot[v] >= n){
                    is_cycle = 1;
                    return;
                }
                if(v == n){
                    reachable = 1;
                }
                if(!inq[v]) q.push(v);
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
    for (int i = 1; i <= m; i++){
        scanf("%d %d %d", &a, &b, &c);
        edges[a].emplace_back(-c, b);
    }
    
    // 需要考虑两种情况，一种存在负环，另外一种是不可到达的情况
    bellman_ford(1);
    if(is_cycle || !reachable){
        printf("%d\n", -1);
    }else{
        printf("%d\n", -dist[n]);   
    }
    return 0;
}