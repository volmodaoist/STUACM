#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define  MAXN  100005

vector<int> edges[MAXN];
int ft[MAXN], dep[MAXN], siz[MAXN], hev[MAXN];
int top[MAXN];
int vist[MAXN];

void tree_build(int u, int father){
    ft[u] = father, dep[u] = dep[father] + 1, siz[u] = 1;
    for(int v: edges[u]){
        if(v == father){
            continue;
        }
        tree_build(v, u);
        siz[u] += siz[v];
        if(siz[hev[u]] < siz[v]) hev[u] = v;
    }
}

void tree_decomposition(int u, int t){
    top[u] = t;
    if(!hev[u]) return;
    tree_decomposition(hev[u], t);
    for (int v : edges[u]){
        if(v == ft[u] || v == hev[u]){
            continue;
        }
        tree_decomposition(v, v);
    }
}

int lca(int u, int v){
    while (top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]])
            swap(u, v);
        u = ft[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}


// 此处判定条件使用小于等于，这样一来叶子节点打印 0 这个需求也就顺便一起解决了
void tree_build_again(int u, int father){
    ft[u] = father, dep[u] = dep[father] + 1;
    for(int v: edges[u]){
        if(v == father)
            continue;
        tree_build_again(v, u);
        siz[u] += siz[v];
        if (siz[hev[u]] <= siz[v]) hev[u] = v;
    }
}


// 这个解法已经被找出了 hack 数据，目前已经无法通过样例了
int main(){ 
    int n, q, a, b, g;
    scanf("%d %d", &n, &q);
    for (int i = 1; i < n; i++){
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    // 本题并没有告诉我们具体哪一个节点是根节点，我们随便选一个作为根节点即可
    tree_build(1, 0);
    tree_decomposition(1, 1);

    memset(siz, 0, sizeof(siz));
    // 谁是根节点并不影响我们计算公共祖先，利用公共祖先进行树上差分更新路径的访问次数
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &a, &b);
        g = lca(a, b);
        if (ft[a] != g) siz[a]++, siz[g]--;
        if (ft[b] != g) siz[b]++, siz[g]--;
    }

    tree_build_again(1, 0);
    for (int i = 1; i <= n; i++){
        printf("%d\n", hev[i]);
    }
    return 0;
}