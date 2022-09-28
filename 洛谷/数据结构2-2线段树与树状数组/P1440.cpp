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
#define  MAXN  5000005


typedef struct _TreeNode{
    int lo, hi, val;
} TreeNode;


int v[MAXN];
TreeNode tree[MAXN];

void build(int lo, int hi, int k = 1) {
    tree[k].lo = lo, tree[k].hi = hi;
    if (lo == hi) {
        tree[k].val = v[lo];
        return;
    }
    int md = (lo + hi) / 2;
    build(lo, md, lc(k));
    build(md + 1, hi, rc(k));
    tree[k].val = min(tree[lc(k)].val, tree[rc(k)].val);
}

int query(int lo, int hi, int k = 1){
    if(lo <= tree[k].lo  && tree[k].hi <= hi){
        return tree[k].val;
    }
    int md = (tree[k].lo + tree[k].hi) / 2;
    int ans = 2e9;
    if (lo <= md) {
        ans = min(ans, query(lo, hi, lc(k)));
    }
    if(hi > md){
        ans = min(ans, query(lo, hi, rc(k)));
    }
    return ans;
}

// 本题如果使用线段树来做需要开启 O2 优化才能通过
int kase;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    build(0, n - 1);
    for (int i = 0; i < n; i++) {
        if(i == 0){
            printf("%d\n", 0);
        }else{
            printf("%d\n", query(max(0, i - m), i - 1));
        }
    }
    return 0;
}