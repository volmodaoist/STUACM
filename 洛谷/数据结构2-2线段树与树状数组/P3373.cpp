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
#define  MAXN  500005

typedef struct _TreeNode{
    int lo, hi;
    llong val, atg, mtg;
} TreeNode;

int v[MAXN], n, m, p;
TreeNode tr[MAXN];

void build(int lo, int hi, int k = 1){
    tr[k].lo = lo, tr[k].hi = hi, tr[k].atg = 0, tr[k].mtg = 1;
    if (tr[k].lo == tr[k].hi) {
        tr[k].val = v[lo] % p;
        return;
    }
    int md = lo + (hi - lo) / 2;
    build(lo, md, lc(k));
    build(md + 1, hi, rc(k));
    tr[k].val = (tr[lc(k)].val + tr[rc(k)].val) % p;
    // printf("lo = %d, hi = %d, val = %lld\n", lo, hi, tr[k].val);
}

void push_down(int k){
    if (tr[k].atg != 0 || tr[k].mtg != 1){
        // 先乘再加
        tr[lc(k)].val = (tr[lc(k)].val * tr[k].mtg + (tr[k].atg * (tr[lc(k)].hi - tr[lc(k)].lo + 1))) % p;
        tr[rc(k)].val = (tr[rc(k)].val * tr[k].mtg + (tr[k].atg * (tr[rc(k)].hi - tr[rc(k)].lo + 1))) % p;

        // 先更新乘法标记再更新加法标记
        tr[lc(k)].mtg = tr[lc(k)].mtg * tr[k].mtg % p;
        tr[rc(k)].mtg = tr[rc(k)].mtg * tr[k].mtg % p;
        tr[lc(k)].atg = (tr[lc(k)].atg * tr[k].mtg + tr[k].atg) % p;
        tr[rc(k)].atg = (tr[rc(k)].atg * tr[k].mtg + tr[k].atg) % p;

        tr[k].atg = 0;
        tr[k].mtg = 1;
    }
}

void print_tree(int k = 1){
    if(tr[k].lo == tr[k].hi){
        printf("lo = %d, hi = %d, val = %lld\n", tr[k].lo, tr[k].hi, tr[k].val);
        return;
    }
    push_down(k);
    int md = (tr[k].lo + tr[k].hi) / 2;
    print_tree(lc(k));
    print_tree(rc(k));
    printf("lo = %d, hi = %d, val = %lld\n", tr[k].lo, tr[k].hi, tr[k].val);

}

void update_mul(int lo, int hi, llong c, int k = 1){
    if(lo <= tr[k].lo && tr[k].hi <= hi){
        tr[k].val = tr[k].val * c % p;
        tr[k].mtg = tr[k].mtg * c % p;
        tr[k].atg = tr[k].atg * c % p;
        return;
    }
    push_down(k);
    int md = (tr[k].lo + tr[k].hi) / 2;
    if(lo <= md)
        update_mul(lo, hi, c, lc(k));
    if(hi > md)
        update_mul(lo, hi, c, rc(k));
    tr[k].val = (tr[lc(k)].val + tr[rc(k)].val) % p;
}

void update_add(int lo, int hi, int c, int k = 1){
    if(lo <= tr[k].lo && tr[k].hi <= hi){
        tr[k].atg = (tr[k].atg + c) % p;
        tr[k].val = (tr[k].val + c * (tr[k].hi - tr[k].lo + 1)) % p;
        return;
    }
    push_down(k);
    int md = (tr[k].lo + tr[k].hi) / 2;
    if (lo <= md)
        update_add(lo, hi, c, lc(k));
    if (hi > md)
        update_add(lo, hi, c, rc(k));
    tr[k].val = (tr[lc(k)].val + tr[rc(k)].val) % p;
}

llong query(int lo, int hi, int k = 1){
    if(lo <= tr[k].lo && tr[k].hi <= hi){
        return tr[k].val;
    }
    push_down(k);
    int md = (tr[k].lo + tr[k].hi) / 2;
    llong ans = 0;
    if (lo <= md)
        ans = (ans + query(lo, hi, lc(k))) % p;
    if(hi > md)
        ans = (ans + query(lo, hi, rc(k))) % p;
    return ans % p;
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    
    scanf("%d %d %d", &n, &m, &p);
    for (int i = 1; i <= n; i++){
        scanf("%d", &v[i]);
    }
    build(1, n);
    int op, a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d", &op);
        if(op == 1){
            scanf("%d %d %d", &a, &b, &c);
            update_mul(a, b, c);
            // printf("乘法, lo = %d, hi = %d, c = %d\n", a, b, c);
        } else if (op == 2) {
            scanf("%d %d %d", &a, &b, &c);
            update_add(a, b, c);
            // printf("加法，lo = %d, hi = %d, c = %d\n", a, b, c);
        } else if (op == 3) {
            scanf("%d %d", &a, &b);
            printf("%lld\n", query(a, b) % p);
            // printf("查询，lo = %d, hi = %d\n", a, b);
        }
    }

    return 0;
}