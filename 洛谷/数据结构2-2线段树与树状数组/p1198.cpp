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
#define  MAXN  200005

#define  lc(x)  (tree[x].lc)
#define  rc(x)  (tree[x].rc)
typedef struct _TreeNode{
    int lo, hi, lc, rc;
    int val;
}TreeNode;



TreeNode tree[MAXN << 5];
int root[MAXN], len[MAXN], n, m, t, z, idx;

// 本题来自洛谷P1198，其实有更简单的做法，此处使用主席树有一点大炮打蚊子的感觉
void build(int lo, int hi, int &x){
    x = ++idx, tree[x].lo = lo, tree[x].hi = hi;
    if (lo == hi) {
        tree[x].val = 0;
        return;
    }
    int md = (lo + hi) / 2;
    build(lo, md, lc(x));
    build(md + 1, hi, rc(x));
    tree[x].val = max(tree[lc(x)].val, tree[rc(x)].val);
}

void update(int u, int &v, int i, int val){
    v = ++idx, tree[v] = tree[u];
    if (tree[v].lo == tree[v].hi && tree[v].lo == i) {
        tree[v].val = val;
        return;
    }
    int md = (tree[v].lo + tree[v].hi) / 2;
    if(i <= md){
        update(lc(u), lc(v), i, val);
    }else{
        update(rc(u), rc(v), i, val);
    }
    tree[v].val = max(tree[lc(v)].val, tree[rc(v)].val);
}

int query(int v, int lo, int hi){
    if (lo <= tree[v].lo && tree[v].hi <= hi){
        return tree[v].val;
    }
    int ans = 0;
    int md = (tree[v].lo + tree[v].hi) / 2;
    if (lo <= md)
        ans = max(ans, query(lc(v), lo, hi));
    if (hi > md)
        ans = max(ans, query(rc(v), lo, hi));
    return ans;
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    char op[3];
    scanf("%d %d", &n, &m);
    build(1, n, root[0]);
    for (int i = 1; i <= n; i++) {
        scanf("%s %d", op, &z);
        if(op[0] == 'A'){
            len[i] = len[i - 1] + 1;
            update(root[i - 1], root[i], len[i], (z + t) % m);
        } else if (op[0] == 'Q') {
            len[i] = len[i - 1];
            root[i] = root[i - 1];
            t = query(root[i], len[i] - z + 1, len[i]) % m;
            printf("%d\n", t);
        }
    }
    return 0;
}