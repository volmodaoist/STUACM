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
#define  MAXN  100005


int heads[MAXN], val[MAXN], nxt[MAXN], idx;
int match[MAXN], vist[MAXN];
int n1, n2, m, a, b;

void add_edge(int a, int b){
    val[idx] = b;
    nxt[idx] = heads[a];
    heads[a] = idx++;
}

int find(int u){
    for (int i = heads[u]; ~i; i = nxt[i]){
        int v = val[i];
        if(!vist[v]){
            vist[v] = 1;
            if(!match[v] || find(match[v])){
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int kase;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d %d %d", &n1, &n2, &m);
    memset(heads, -1, sizeof(heads));
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        add_edge(a, b);
    }
    // 注意二分图是有向图的, 加边的时候能把顺序交换, 改成 add_edge(b, a)
    // 然后再把下面的 n1 改成 n2 即可
    int ans = 0;
    for (int i = 0; i <= n1; i++){
        memset(vist, 0, sizeof(vist));
        if(find(i)){
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}