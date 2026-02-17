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

int n, m, a, b;
int heads[MAXN], val[MAXN], nxt[MAXN], idx;
int vist[MAXN];

void add_edge(int a, int b) {
    val[idx] = b;
    nxt[idx] = heads[a];
    heads[a] = idx++;
}

// 0代表没有染色，1 代表白色， 2 代表黑色
bool dfs(int u, int color){
    vist[u] = color;
    for (int i = heads[u]; ~i; i = nxt[i]){
        int v = val[i];
        if (!vist[v]) {
            if(!dfs(v, 3 - color)){
                return false;
            }
        } else if(vist[v] == color){
            return false;
        }
    }
    return true;
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    // 由于无向图需要存边两次，因而数容量至少得是边数的两倍，
    // 否则有可能会因为idx越界导致TLE! 
    
    scanf("%d %d", &n, &m);
    memset(heads, -1, sizeof(heads));
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        add_edge(a, b);
        add_edge(b, a);
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if(!vist[i]){
           if(!dfs(i, 1)){
               flag = false;
               break;
           }
        }
    }
    printf("%s\n", flag ? "Yes" : "No");
    return 0;
}