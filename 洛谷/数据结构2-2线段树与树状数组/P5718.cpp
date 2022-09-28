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

typedef struct TreeNode{
    int lo, hi, val;
} TreeNode;

TreeNode tree[MAXN];
int v[MAXN];
int n, m, a, b;

void build(int k, int lo, int hi) {
    tree[k].lo = lo, tree[k].hi = hi;
    if(lo == hi){
        tree[k].val = v[lo];
        return;
    }
    int md = lo + (hi - lo) / 2;
    build(lc(k), lo, md);
    build(rc(k), md + 1, hi);
    tree[k].val = min(tree[lc(k)].val, tree[rc(k)].val);
}

// 其实只要实现区间更新就好，单坐标更新是区间更新的一个特例
void update(int k, int i, int val){
    if(tree[k].lo == tree[k].hi && tree[k].lo == i){
        tree[k].val = val;
        return;
    }
    int md = (tree[k].lo + tree[k].hi) / 2;
    if(i <= md){
        update(lc(k), i, val);
    } else {
        update(rc(k), i, val);
    }
    tree[k].val = min(tree[lc(k)].val, tree[rc(k)].val);
}

// 线段树具有区间覆盖，以及区间相等两种做法, 区间覆盖法相当于是用一张网去套区间，这张网的大小一直不变的！
int query(int k, int lo, int hi){
    if(lo <= tree[k].lo && tree[k].hi <= hi){
        return tree[k].val;
    }
    int md = (tree[k].lo + tree[k].hi) / 2;
    int ans = 2e9;
    if (lo <= md)
        ans = min(ans, query(lc(k), lo, hi));
    if (hi > md)
        ans = min(ans, query(rc(k), lo, hi));
    return ans;
}

void debug_print_tree(){
    for (int i = 1; i <= 4 * n; i++){
        printf("tree[%d], lo = %d, hi = %d, val = %d\n", i, tree[i].lo, tree[i].hi, tree[i].val);
    }
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif


    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &v[i]);
    }
    build(1, 1, n);
    printf("%d\n", query(1, 1, n));
    return 0;
}