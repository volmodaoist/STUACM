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
#define  MAXN  500005



#define  lc(x)  (tree[x].lc)
#define  rc(x)  (tree[x].rc)
typedef struct _TreeNode{
    int lc, rc;
    int s;
}TreeNode;

TreeNode tree[MAXN * 22];
int v[MAXN], root[MAXN], idx;

void build(int lo, int hi, int &x){
    x = ++idx;
    if(lo == hi){
        return;
    }
    int md = (lo + hi) / 2;
    build(lo, md, lc(x));
    build(md + 1, hi, rc(x));
}


void update(int u, int &v, int lo, int hi, int val){
    v = ++idx, tree[v] = tree[u], tree[v].s++;
    if(lo == hi){
        return;
    }
    int md = (lo + hi) / 2;
    if(val <= md){
        update(lc(u), lc(v), lo, md, val);
    } else {
        update(rc(u), rc(v), md + 1, hi, val);
    }
}

int query(int u, int v, int lo, int hi, int len){
    if(lo == hi){
        return lo;
    }
    int md = (lo + hi) / 2;
    
    // 如果位于左边区域的数据乘以2大于区间长度，说明左半区域存在某个数数量严格大于区间长度一半
    // 如果位于右边区域的数据乘以2大于区间长度，说明右半区域存在某个数数量严格大于区间长度一半
    if (2 * (tree[lc(v)].s - tree[lc(u)].s) > len)
        return query(lc(u), lc(v), lo, md, len);
    if (2 * (tree[rc(v)].s - tree[rc(u)].s) > len)
        return query(rc(u), rc(v), md + 1, hi, len);
    return 0;
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, m, vmax = 500000;
    scanf("%d %d", &n, &m);
    
    // build(1, vmax, root[0]);
    
    root[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        update(root[i - 1], root[i],  1, vmax, v[i]);
    }
    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", query(root[a - 1], root[b], 1, vmax, b - a + 1));
    }
    return 0;
}