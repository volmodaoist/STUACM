#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
#define  MAXN  100005

vector<int> edges[MAXN];
int ft[MAXN], dep[MAXN], siz[MAXN], hev[MAXN], idx;
int w[MAXN], top[MAXN], id[MAXN], nw[MAXN];

void tree_build(int u, int father){
    ft[u] = father, dep[u] = dep[father] + 1, siz[u] = 1;
    for (int v: edges[u]){
        if(v == father){
            continue;
        }
        tree_build(v, u);
        siz[u] += siz[v];
        if(siz[hev[u]] < siz[v]){
            hev[u] = v;
        }
    }
}

void tree_decomposition(int u, int t){
    top[u] = t, id[u] = ++idx, nw[idx] = w[u];
    if(!hev[u]) return;
    tree_decomposition(hev[u], t);
    for (int v : edges[u]) {
        if (v == ft[u] || v == hev[u]) {
            continue;
        }
        tree_decomposition(v, v);
    }
}


#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
typedef struct _TreeNode{
    int lo, hi;
    ill atg, val;
} TreeNode;

TreeNode tree[MAXN << 2];


int n, m, r, p;
int a, b, op, x, z;

void build(int lo, int hi, int k = 1){
    tree[k].lo = lo, tree[k].hi = hi, tree[k].val = 0;
    if (lo == hi) {
        tree[k].val = nw[lo];
        return;
    }
    int md = (lo + hi) / 2;
    build(lo, md, lc(k));
    build(md + 1, hi, rc(k));
    tree[k].val = (tree[lc(k)].val + tree[rc(k)].val) % p;
}

void push_down(int k){
    if(tree[k].atg){
        tree[lc(k)].val = (tree[lc(k)].val + tree[k].atg * (tree[lc(k)].hi - tree[lc(k)].lo + 1)) % p;
        tree[rc(k)].val = (tree[rc(k)].val + tree[k].atg * (tree[rc(k)].hi - tree[rc(k)].lo + 1)) % p;
        tree[lc(k)].atg += tree[k].atg;
        tree[rc(k)].atg += tree[k].atg;
        tree[k].atg = 0;
    }
}

void update(int lo, int hi, int c, int k = 1){
    if (lo <= tree[k].lo && tree[k].hi <= hi){
        tree[k].val = (tree[k].val + c * (tree[k].hi - tree[k].lo + 1)) % p;
        tree[k].atg += c;
        return;
    }
    push_down(k);
    int md = (tree[k].lo + tree[k].hi) / 2;
    if (lo <= md) 
        update(lo, hi, c, lc(k));
    if(hi > md)
        update(lo, hi, c, rc(k));
    tree[k].val = (tree[lc(k)].val + tree[rc(k)].val) % p;
}

ill query(int lo, int hi, int k = 1){
    if(lo <= tree[k].lo && tree[k].hi <= hi){
        return tree[k].val;
    }
    push_down(k);
    int md = (tree[k].lo + tree[k].hi) / 2;
    ill ans = 0;
    if (lo <= md)
        ans = (ans + query(lo, hi, lc(k))) % p;
    if (hi > md)
        ans = (ans + query(lo, hi, rc(k))) % p;
    return ans;
}

void update_path(int u, int v, int c){
    while (top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]])
            swap(u, v);
        update(id[top[u]], id[u], c);
        u = ft[top[u]];
    }
    if(dep[u] < dep[v]) swap(u, v);
    update(id[v], id[u], c);
}

void update_subtree(int u, int c){
    update(id[u], id[u] + siz[u] - 1, c);
}

ill query_path(int u, int v, int k = 1) {
    ill ans = 0;
    while (top[u] != top[v]) {
        if(dep[top[u]] < dep[top[v]])
            swap(u, v);
        ans += query(id[top[u]], id[u]) % p;
        u = ft[top[u]];
    }
    if(dep[u] < dep[v]) swap(u, v);
    ans += query(id[v], id[u]) % p;
    return ans % p;
}

ill query_subtree(int u){
    return query(id[u], id[u] + siz[u] - 1) % p;
}


int main() {
    scanf("%d %d %d %d", &n, &m, &r, &p);
    for (int i = 1; i <= n; i++){
        scanf("%d", &w[i]);
    }

    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    tree_build(r, 0);
    tree_decomposition(r, r);
    build(1, idx);
    for (int i = 0; i < m; i++) {
        scanf("%d", &op);
        if(op == 1){
            // 两个节点之间最短路径上面所有节点+z
            scanf("%d %d %d", &a, &b, &z);
            update_path(a, b, z);
        } else if (op == 2) {
            // 计算x与的y两个节点的路径之和
            scanf("%d %d", &a, &b);
            printf("%lld\n", query_path(a, b));
        } else if (op == 3) {
            // 所有子树的节点值 + z
            scanf("%d %d", &x, &z);
            update_subtree(x, z);
        } else if (op == 4) {
            // 计算整个子树的所有节点和
            scanf("%d", &x);
            printf("%lld\n", query_subtree(x));
        }
    }
    return 0;
}