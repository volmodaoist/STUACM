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
typedef struct _TreeNode{
    int lc, rc;
    int val;
}TreeNode;

// 这一版的代码是根据董晓算法的视频改过的，更加简洁而且减少了空间消耗
TreeNode tree[MAXN << 5];
int A[MAXN], root[MAXN], idx;

void build(int lo, int hi, int &x){
    x = ++idx;
    if (lo == hi) {
        tree[x].val = A[lo];
        return;
    }
    int md = (lo + hi) / 2;
    build(lo, md, lc(x));
    build(md + 1, hi, rc(x));
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
}

int query(int u, int lo, int hi, int i){
    if(lo == hi){
        return tree[u].val;
    }
    int md = (lo + hi) / 2;
    if(i <= md){
        return query(lc(u), lo, md, i);
    } else {
        return query(rc(u), md + 1, hi, i);
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
            update(root[v], root[i], 1, n, loc, val);
        } else if (op == 2) {
            scanf("%d", &loc);
            printf("%d\n", query(root[v], 1, n, loc));
            root[i] = root[v];
        }
    }
    return 0;
}