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
int vist[MAXN];
int reach[MAXN];
vector<int> edges[MAXN];


void dfs(int u){
    vist[u] = 1, reach[u] = max(reach[u], u);
    for (int v : edges[u]) {
        if(!vist[v]){
            reach[v] = max(reach[v], reach[u]);
            dfs(v);
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
        edges[b].push_back(a);
    }
    for (int i = n; i >= 1; i--){
        dfs(i);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", reach[i]);
    }
    printf("\n");
    return 0;
}