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
#define  MAXN  100005

int n, m, op, pos, x;

#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)

typedef struct _TreeNode{
    int lo, hi;
    llong val;
} TreeNode;

TreeNode tree[MAXN << 2];

void build(int lo, int hi, int k = 1){
    tree[k].lo = lo, tree[k].hi = hi;
    if (lo == hi) {
        tree[k].val = 1;
        return;
    }
    int md = (lo + hi) / 2;
    build(lo, md, lc(k));
    build(md + 1, hi, rc(k));
    tree[k].val = (tree[lc(k)].val * tree[rc(k)].val) % m;
}

void update(int i, int val, int k = 1){
    if(tree[k].lo == tree[k].hi && tree[k].lo == i){
        tree[k].val = val;
        return;
    }
    int md = (tree[k].lo + tree[k].hi) / 2;
    if (i <= md){
        update(i, val, lc(k));
    }else{
        update(i, val, rc(k));
    }
    tree[k].val = (tree[lc(k)].val  * tree[rc(k)].val) % m;
}

llong query(int lo, int hi, int k = 1){
    if(lo <= tree[k].lo && tree[k].hi <= hi){
        return tree[k].val;
    }
    llong ans = 1;
    int md = (tree[k].lo + tree[k].hi) / 2;
    if (lo <= md){
        ans = ans * query(lo, hi, lc(k)) % m;
    }
    if(hi > md){
        ans = ans * query(lo, hi, rc(k)) % m;
    }
    return ans % m;
}

int kase;
int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d", &kase);
    while(kase--){
        scanf("%d %d", &n, &m);
        build(1, n);
        for (int i = 1; i <= n; i++){
            scanf("%d", &op);
            if(op == 1){
                scanf("%d", &x);
                update(i, x);
                printf("%lld\n", query(1, n) % m);
            } else if (op == 2) {
                scanf("%d", &pos);
                update(pos, 1);
                printf("%lld\n", query(1, n) % m);
            }
        }
    }
    return 0;
}