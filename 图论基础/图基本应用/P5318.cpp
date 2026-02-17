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
#define  MAXN  1000005

int n, m, a, b;
bool vist[MAXN], has_father[MAXN];
vector<ii> tmp_edges;
vector<int> edges[MAXN];
vector<int> ans;

void dfs(int u){
    vist[u] = 1;
    printf("%d ", u);
    for (int v : edges[u]) {
        if(!vist[v]){
            dfs(v);
        }
    }
}

void bfs(int u){
    memset(vist, 0, sizeof(vist));
    printf("%d ", u);
    queue<int> q;
    vist[u] = 1;
    q.push(u);
    while(q.size()){
        int u = q.front(); q.pop();
        for (int v: edges[u]){
            if(!vist[v]){
                vist[v] = 1;
                printf("%d ", v);
                q.push(v);
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
    for (int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        has_father[b] = 1;
    }

    for (int i = 1; i <= n; i++) {
        sort(edges[i].begin(), edges[i].end());
    }

    dfs(1);
    printf("\n");
    bfs(1);
    printf("\n");
    return 0;
}