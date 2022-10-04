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


typedef long long LLong;
typedef unsigned long long ULL;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
#define  fi    first
#define  se    second
#define  MAXN  500005

vector<int> edges[MAXN];
int dep[MAXN], fa[MAXN][25];


// 倍增法打表查询公共祖先
void dfs(int u, int father){
    dep[u] = dep[father] + 1;
    fa[u][0] = father;
    for(int i = 1; i <= 20; i++){
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    } 
    for(int v :  edges[u]){
        if(v != father){
            dfs(v, u);
        }
    }
}

int lca(int u, int v){
    if(dep[u] < dep[v]) 
        swap(u, v);
    // 顶点 u 处在更深的位置
    for(int i = 20; i>=0; i--){
        if(dep[fa[u][i]] >= dep[v]){
            u = fa[u][i];
        }
    }
    if(u == v) return v;
    for(int i = 20; i >= 0; i--){
        if(fa[u][i] != fa[v][i]){
            u = fa[u][i], v = fa[v][i];
        }
    }
    return fa[u][0];
}


int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, m, s, a, b;
    scanf("%d %d %d", &n, &m, &s);
    for(int i = 1; i < n; i++){
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(s, 0);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}