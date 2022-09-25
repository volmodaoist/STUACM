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


typedef long long llong;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
#define  MAXN  400005

typedef struct _TreeNode{
    int lo, hi;
    llong val, tag;
} TreeNode;

TreeNode tree[MAXN];
llong v[MAXN];

void build(int k, int lo, int hi) {
    tree[k].lo = lo, tree[k].hi = hi, tree[k].tag = 0;
    if (lo == hi) {
        tree[k].val = v[lo];
        return;
    }
    int md = lo + (hi - lo) / 2;
    build(lc(k), lo, md);
    build(rc(k), md + 1, hi);
    tree[k].val = tree[lc(k)].val + tree[rc(k)].val;
}

// 懒标记不为零的时候向下传播
void push_down(int k){
    if(tree[k].tag != 0){
        tree[lc(k)].val += tree[k].tag * (tree[lc(k)].hi - tree[lc(k)].lo + 1);
        tree[rc(k)].val += tree[k].tag * (tree[rc(k)].hi - tree[rc(k)].lo + 1);
        tree[lc(k)].tag += tree[k].tag;
        tree[rc(k)].tag += tree[k].tag;
        tree[k].tag = 0;
    }
}

// 区间更新
void update(int k, int lo, int hi, llong val){
    if(lo <= tree[k].lo && tree[k].hi <= hi){
        tree[k].val += val * (tree[k].hi - tree[k].lo + 1);
        tree[k].tag += val;
        return;
    }
    push_down(k);
    int md = (tree[k].lo + tree[k].hi) / 2;
    if (lo <= md)
        update(lc(k), lo, hi, val);
    if(hi > md)
        update(rc(k), lo, hi, val);
    tree[k].val = tree[lc(k)].val + tree[rc(k)].val;
}

llong query(int k, int lo, int hi){
    if(lo <= tree[k].lo && tree[k].hi <= hi){
        return tree[k].val;
    }
    push_down(k);
    int md = (tree[k].lo + tree[k].hi) / 2;
    llong ans = 0;
    if (lo <= md)
        ans += query(lc(k), lo, hi);
    if (hi > md)
        ans += query(rc(k), lo, hi);
    return ans;
}

int kase;
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
    build(1, 1, n);
    int op, a, b, z;
    for (int i = 0; i < m; i++) {
        scanf("%d", &op);
        if(op == 1){
            scanf("%d %d %d", &a, &b, &z);
            update(1, a, b, z);
        } else {
            scanf("%d %d", &a, &b);
            printf("%lld\n", query(1, a, b));
        }
    }
    return 0;
}