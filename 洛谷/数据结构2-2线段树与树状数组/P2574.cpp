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

#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
typedef struct _TreeNode{
    int lo, hi;
    int val, atg;
} TreeNode;


TreeNode tree[MAXN << 2];
int v[MAXN];

// 线段树能够维护区间加法、乘法、赋值，利用和差化积公式还能维护区间sin/cos
void build(int lo, int hi, int k = 1) {
    tree[k].lo = lo, tree[k].hi = hi, tree[k].atg = 0;
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
    return;
}

void push_down(int k){
    if (tree[k].atg != 0){
        tree[lc(k)].val = ((tree[lc(k)].hi - tree[lc(k)].lo + 1) -  tree[lc(k)].val);
        tree[rc(k)].val = ((tree[rc(k)].hi - tree[rc(k)].lo + 1) - tree[rc(k)].val);
        tree[lc(k)].atg ^= tree[k].atg;
        tree[rc(k)].atg ^= tree[k].atg;
        tree[k].atg = 0;
    }
}

// 由于元素都是零一，那么区间维护的总和也即数字 1 个数，0 个数也即区间长度减去总和
void update(int lo, int hi, int k = 1){
    if (lo <= tree[k].lo && tree[k].hi <= hi) {
        int len = tree[k].hi - tree[k].lo + 1;
        tree[k].val = len - tree[k].val;
        tree[k].atg ^= 1;
        return;
    }
    push_down(k);
    int md = (tree[k].lo + tree[k].hi) / 2;
    if (lo <= md)
        update(lo, hi, lc(k));
    if (hi > md)
        update(lo, hi, rc(k));
    tree[k].val = tree[lc(k)].val + tree[rc(k)].val;
}

int query(int lo, int hi, int k = 1){
    if (lo <= tree[k].lo && tree[k].hi <= hi){
        return tree[k].val;
    }
    push_down(k);
    int md = (tree[k].lo + tree[k].hi) / 2;
    int ans = 0;
    if (lo <= md)
        ans += query(lo, hi, lc(k));
    if (hi > md)
        ans += query(lo, hi, rc(k));
    return ans;
}

int kase;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, m, op, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%1d", &v[i]);
    }
    build(1, n);
    // print_tree(1, n);
    while (m--) {
        scanf("%d %d %d", &op, &a, &b);
        if (op == 0) {
            update(a, b);
        } else if (op == 1) {
            printf("%d\n", query(a, b));
        }
    }
    return 0;
}