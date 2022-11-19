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
typedef unsigned long long ull;
#define  MAXN  100005

int n, m, a, b, c;
vector<int> edges[MAXN];
int dist[MAXN], path[MAXN];

void bfs(int s = 1){
    memset(dist, 0x3f, sizeof(dist));
    queue<int> q; 
    q.push(s);
    dist[s] = 0, path[s] = 1;
    while (q.size()) {
        int u = q.front(); q.pop();
        for(int v: edges[u]){
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
            if (dist[v] == dist[u] + 1) {
                path[v] += path[u];
                path[v] %= 100003;
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
    for (int i = 0; i < m ; i++){
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    bfs();
    for (int i = 1; i <= n; i++){
        printf("%d\n", path[i]);
    }
    return 0;
}