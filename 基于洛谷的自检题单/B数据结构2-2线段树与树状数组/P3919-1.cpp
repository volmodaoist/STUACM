#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long llong;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
#define  MAXN  1000005

// 这一版的代码是自己根据理解写出来的，但是结构体里面的 lo、hi 其实是可以不存储的
#define  lc(x)  (tree[x].lc)
#define  rc(x)  (tree[x].rc)
typedef struct _TreeNode{
    int lo, hi, lc, rc;
    int val;
}TreeNode;

TreeNode tree[MAXN << 5];
int A[MAXN], root[MAXN], idx;

void build(int lo, int hi, int &x){
    x = ++idx, tree[x].lo = lo, tree[x].hi = hi;
    if (lo == hi) {
        tree[x].val = A[lo];
        return;
    }
    int md = (lo + hi) / 2;
    build(lo, md, lc(x));
    build(md + 1, hi, rc(x));
}

// u 传入一个树节点，使用 root ith 版本号的树节点
int update(int u, int i, int val){
    int v = ++idx;
    tree[v] = tree[u];
    if (tree[v].lo == tree[v].hi && tree[v].lo == i) {
        tree[v].val = val;
        return v;
    }
    int md = (tree[u].lo + tree[u].hi) / 2;
    if(i <= md){
        lc(v) = update(lc(u), i, val);
    } else {
        rc(v) = update(rc(u), i, val);
    }
    return v;
}

int query(int u, int i){
    int v = ++idx;
    tree[v] = tree[u];
    if(tree[v].lo == tree[v].hi && tree[v].lo == i){
        return tree[v].val;
    }
    int md = (tree[u].lo + tree[u].hi) / 2;
    if(i <= md){
        return query(lc(u), i);
    }else{
        return query(rc(u), i);
    }
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%d", &A[i]);
    }
    build(1, n, root[0]);
    int v, op, loc, val;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &v, &op);
        if(op == 1){
            scanf("%d %d", &loc, &val);
            root[i] = update(root[v], loc, val);
        } else if (op == 2) {
            scanf("%d", &loc);
            printf("%d\n", query(root[v], loc));
            root[i] = root[v];
        }
    }
    return 0;
}