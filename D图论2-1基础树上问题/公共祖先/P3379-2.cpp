#include<bits/stdc++.h>
using namespace std;

#define MAXN 500005
vector<int> edges[MAXN];
int dep[MAXN], ft[MAXN], siz[MAXN], hev[MAXN], top[MAXN];
int n, m, s, a, b;


// 深搜获取深度，父节点，重链头节点，以及子树大小
void tree_build(int u, int father){
    ft[u] = father, dep[u] = dep[father] + 1, siz[u] = 1;
    for(int v : edges[u]){
        if(v == father)
            continue;
        tree_build(v, u);
        siz[u] += siz[v];
        if(siz[hev[u]] < siz[v]) hev[u] = v;
    }
}

// 获取了树结构基本信息之后开始树链剖分，通过链头唯一的标识一条重链
void tree_decomposition(int u, int t){
    top[u] = t;
    if(!hev[u]) return;
    tree_decomposition(hev[u], t);
    for(int v: edges[u]){
        if(v == ft[u] || v == hev[u])
            continue;
        tree_decomposition(v, v);
    }
}

int lca(int u, int v){
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]])
            swap(u, v);
        u = ft[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}

int main(){
    scanf("%d %d %d",&n, &m, &s);
    for(int i = 1; i < n; i++){
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    tree_build(s, 0);
    tree_decomposition(s, 0);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}