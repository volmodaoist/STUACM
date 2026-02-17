#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  MAXN  50005


#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
typedef struct _TreeNode{
    int lo, hi;
    int val;
} TreeNode;
TreeNode tree[MAXN << 2];
int v[MAXN];

void build(int lo, int hi, int k = 1){
    tree[k].lo = lo, tree[k].hi = hi;
    if (lo == hi) {
        tree[k].val = v[lo];
        return;
    }
    int md = (lo + hi) / 2;
    build(lo, md, lc(k));
    build(md + 1, hi, rc(k));
    tree[k].val = tree[lc(k)].val + tree[rc(k)].val;
}

void print_tree(int lo, int hi, int k = 1){
    if(lo == hi){
        printf("lo = %d, hi = %d, val = %d\n", tree[k].lo, tree[k].hi, tree[k].val);
        return;
    }
    int md = (lo + hi) / 2;
    print_tree(lo, md, lc(k));
    print_tree(md + 1, hi, rc(k));
    printf("lo = %d, hi = %d, val = %d\n", tree[k].lo, tree[k].hi, tree[k].val);
}

void update(int i,  int val, int k = 1){
    if(tree[k].lo == tree[k].hi && tree[k].lo == i){
        tree[k].val += val;
        return;
    }
    int md = (tree[k].lo + tree[k].hi) / 2;
    if (i <= md){
        update(i, val, lc(k));
    } else {
        update(i, val, rc(k));
    }
    tree[k].val = tree[lc(k)].val + tree[rc(k)].val;
}


int query(int lo, int hi, int k = 1){
    if(lo <= tree[k].lo && tree[k].hi <= hi){
        return tree[k].val;
    }
    int md = (tree[k].lo + tree[k].hi) / 2;
    int ans = 0;
    if (lo <= md) {
        ans += query(lo, hi, lc(k));
    }
    if(hi > md){
        ans += query(lo, hi, rc(k));
    }
    return ans;
}

int kase, n, a, b, pos, val;
int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    char op[8];
    scanf("%d", &kase);
    for (int k = 1; k <= kase; k++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            scanf("%d", &v[i]);
        }
        build(1, n);
        // print_tree(1, n);
        printf("Case %d:\n", k);
        while(scanf("%s", op) && op[0] != 'E'){
            if (op[0] == 'A') {
                scanf("%d %d", &pos, &val);
                update(pos, val);
            } else if (op[0] == 'S') {
                scanf("%d %d", &pos, &val);
                update(pos, -val);
            } else if (op[0] == 'Q') {
                scanf("%d %d", &a, &b);
                printf("%d\n", query(a, b));
            }
        }
    }
    return 0;
}