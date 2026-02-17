#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

typedef long long ill;
typedef unsigned long long ull;

#define  MAXN  100005

vector<int> edges[MAXN];
int d[MAXN], farthest = 0;

// 两次dfs 计算树结构的直径，需要注意这种方法边权不允许存在负数
void dfs(int u, int father) {
    for (int v: edges[u]){
        if(v == father)
            continue;
        d[v] = d[u] + 1;
        if(d[farthest] < d[v]){
            farthest = v;
        }
        dfs(v, u);
    }
}

int kase;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, a, b;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(1, 0);
    d[farthest] = 0;
    dfs(farthest, 0);

    printf("%d\n", d[farthest]);
    return 0;
}