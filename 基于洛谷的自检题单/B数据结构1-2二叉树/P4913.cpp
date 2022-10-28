#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  MAXN  5000005



#define  lc(x)  ((x << 1))
#define  rc(x)  ((x << 1)|1)

int tr[MAXN];
int has_father[MAXN], mdep;

void dfs(int u, int dep) {
    if(u == 0)
        return;
    mdep = max(mdep, dep);
    dfs(tr[lc(u)], dep + 1);
    dfs(tr[rc(u)], dep + 1);
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, a, b;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d %d", &a, &b);
        tr[lc(i)] = a;
        tr[rc(i)] = b;
        has_father[a] = has_father[b] = 1;
    }
    
    int root = 1;
    while (has_father[root]){
        root++;
    }

    dfs(root, 1);
    printf("%d\n", mdep);
    return 0;
}