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
#define  MAXN  500005


typedef struct _TreeNode{
    int lo, hi;
    ill val, tag;
} TreeNode;

TreeNode tr[MAXN];
int v[MAXN];

void build(int lo, int hi, int k = 1){
    tr[k].lo = lo, tr[k].hi = hi, tr[k].tag = 0;
    if (tr[k].lo == tr[k].hi) {
        tr[k].val = v[lo];
        return;
    }
    int md = lo + (hi - lo) / 2;
    build(lo, md, lc(k));
    build(md + 1, hi, rc(k));
    tr[k].val = tr[lc(k)].val + tr[rc(k)].val;
}

void push_down(int k){
    if (tr[k].tag != 0){
        tr[lc(k)].val += tr[k].tag * (tr[lc(k)].hi - tr[lc(k)].lo + 1);
        tr[rc(k)].val += tr[k].tag * (tr[rc(k)].hi - tr[rc(k)].lo + 1);
        tr[lc(k)].tag += tr[k].tag;
        tr[rc(k)].tag += tr[k].tag;
        tr[k].tag = 0;
    }
}

void update(int lo, int hi, int c, int k = 1) {
    if (lo <= tr[k].lo && tr[k].hi <= hi) {
        tr[k].val += c * (tr[k].hi - tr[k].lo + 1);
        tr[k].tag += c;
        return;
    }
    push_down(k);
    int md = (tr[k].lo + tr[k].hi) / 2;
    if (lo <= md)
        update(lo, hi, c, lc(k));
    if(hi > md)
        update(lo, hi, c, rc(k));
    tr[k].val = tr[lc(k)].val + tr[rc(k)].val;
}

ill query(int lo, int hi, int k = 1){
    if(lo <= tr[k].lo && tr[k].hi <= hi){
        return tr[k].val;
    }
    push_down(k);
    int md = (tr[k].lo + tr[k].hi) / 2;
    ill ans = 0;
    if (lo <= md)
        ans += query(lo, hi, lc(k));
    if (hi > md)
        ans += query(lo, hi, rc(k));
    return ans;
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%d", &v[i]);
    }

    build(1, n);
    int op, k, a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d", &op);
        if(op == 1){
            scanf("%d %d %d", &a, &b, &k);
            update(a, b, k);
        } else if (op == 2) {
            scanf("%d %d", &a, &b);
            printf("%lld\n", query(a, b));
        }
    }

    return 0;
}