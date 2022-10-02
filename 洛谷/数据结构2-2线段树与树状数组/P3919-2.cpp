#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


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

#define  lc(x)  (tree[x].lc)
#define  rc(x)  (tree[x].rc)

/**
 * 树节点维护 lo、hi 区间其实是可以不用存储的，
 * 只要查询的时候传入一下 tree_lo, tree_hi 即可，
 * 此处存储端点区间是为了编写代码的时候更加简洁，逻辑更加清晰
*/
typedef struct _TreeNode{
    int lo, hi, lc, rc;
    llong val;
}TreeNode;

// 这一版的代码结合自己理解，并根据董晓算法的视频改过的，更加简洁而且减少了空间消耗
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
    tree[x].val = tree[lc(x)].val + tree[rc(x)].val;
}

// u 传入一个树节点，使用 root ith 版本号的树节点
void update(int u, int &v, int lo, int hi, int i, int val){
    v = ++idx, tree[v] = tree[u];
    if (lo == hi) {
        tree[v].val = val;
        return;
    }
    int md = (lo + hi) / 2;
    if (i <= md) {
        update(lc(u), lc(v), lo, md, i, val);
    } else {
        update(rc(u), rc(v), md + 1, hi, i, val);
    }
    tree[v].val = tree[lc(v)].val + tree[rc(v)].val;
}

llong query(int u,  int i){
    if(tree[u].lo == tree[u].hi && tree[u].lo == i){
        return tree[u].val;
    }
    int md = (tree[u].lo + tree[u].hi) / 2;
    if(i <= md){
        return query(lc(u), i);
    } else {
        return query(rc(u),  i);
    }
}

// 本题并不要求实现区间查询，但是使用区间能够使本题模板更加一般化
llong query(int u,  int lo, int hi){
    // 如果查询区间覆盖了树节点维护的区间则返回
    if (lo <= tree[u].lo && tree[u].hi <= hi) {
        return tree[u].val;
    }
    int md = (tree[u].lo + tree[u].hi) / 2;
    llong ans = 0;
    if(lo <= md)
        ans += query(lc(u), lo, hi);
    if (hi > md)
        ans += query(rc(u), lo, hi);
    return ans;
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
            update(root[v], root[i], 1, n, loc, val);
        } else if (op == 2) {
            scanf("%d", &loc);
            printf("%lld\n", query(root[v], loc));
            root[i] = root[v];
        }
    }
    return 0;
}