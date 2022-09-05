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


typedef long long llong;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
#define  fi    first
#define  se    second
#define  MAXN  500005

vector<int> edges[MAXN];
vector<ii> query[MAXN];
int ft[MAXN], vist[MAXN], ans[MAXN];
int n, m, s, a, b;

// tarjan算法计算最近公共祖先
int find(int x){
    return x != ft[x] ? (ft[x] = find(ft[x])) : ft[x];
}

void tarjan(int u){
    vist[u] = true;
    for(int v : edges[u]){
        if(!vist[v]){
            tarjan(v);
            ft[v] = u;
        }
    }
    for(auto q : query[u]){
        int v = q.first, i = q.second;
        if(vist[v]){
            ans[i] = find(v);
        }
    }
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i < n;  i++){
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        query[a].push_back({b, i});
        query[b].push_back({a, i});
    }
    for (int i = 1; i <= n; i++){
        ft[i] = i;
    }
    tarjan(s);
    for (int i = 0; i < m; i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}