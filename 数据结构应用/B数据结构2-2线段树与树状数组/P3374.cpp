#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	CLEAR(A,x)  (memset(A,x,sizeof(A)))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
#define  MAXN  800005


typedef struct _TreeNode{
    int lo, hi;
    ill val;
} TreeNode;

TreeNode tree[MAXN << 2];
int v[MAXN];

void build(int lo, int hi, int k = 1){
    tree[k].lo = lo, tree[k].hi = hi;
    if (tree[k].lo == tree[k].hi) {
        tree[k].val = v[lo];
        return;
    }
    int md = lo + (hi - lo) / 2;
    build(lo, md, lc(k));
    build(md + 1, hi, rc(k));
    tree[k].val = tree[lc(k)].val + tree[rc(k)].val;
}

void update(int i, int val, int k = 1) {
    tree[k].val += val;
    if(tree[k].lo == tree[k].hi){
        return;
    }
    int md = (tree[k].lo + tree[k].hi) / 2;
    if(i <= md){
        update(i, val, lc(k));
    }else{
        update(i, val, rc(k));
    }
}

ill query(int lo, int hi, int k = 1){
    if(tree[k].lo == lo && tree[k].hi == hi){
        return tree[k].val;
    }
    int md = (tree[k].lo + tree[k].hi) / 2;
    if(hi <= md){
        return query(lo, hi, lc(k));
    }else if(lo > md){
        return query(lo, hi, rc(k));
    } else {
        return query(lo, md, lc(k)) + query(md + 1, hi, rc(k));
    }
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%d", &v[i]);
    }

    build(1, n);
    int op, k, a, b, pos, x;
    for (int i = 0; i < m; i++) {
        scanf("%d", &op);
        if(op == 1){
            scanf("%d %d", &pos, &x);
            update(pos, x);
        } else if (op == 2) {
            scanf("%d %d", &a, &b);
            printf("%lld\n", query(a, b));
        }
    }

    return 0;
}