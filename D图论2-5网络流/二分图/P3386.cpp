#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
#define  MAXN  100005

int match[MAXN], vist[MAXN];
vector<int> edges[MAXN];

bool dfs(int u){
    for (int v: edges[u]){
        if(!vist[v]){
            vist[v] = 1;
            if (!match[v] || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    int n, m, e, a, b;
    scanf("%d %d %d", &n, &m, &e);
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &a, &b);
        edges[b].push_back(a);
    }
    int ans = 0;
    for (int i = 1; i <= m; i++){
        memset(vist, 0, sizeof(int) * n);
        if(dfs(i)){
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}