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
#define  MAXN  600005


// 本题由于没有tag使用llong, WA好几次
typedef struct _TreeNode{
    int lo, hi;
    llong tag;
    double sine, cosi;
} TreeNode;

TreeNode tree[MAXN << 2];
int v[MAXN];

void build(int lo, int hi, int k = 1){
    tree[k].lo = lo, tree[k].hi = hi;
    if (lo == hi) {
        tree[k].sine = sin(v[lo]), tree[k].cosi = cos(v[lo]);
        return;
    }
    int md = (lo + hi) / 2;
    build(lo, md, lc(k));
    build(md + 1, hi, rc(k));
    tree[k].sine = tree[lc(k)].sine + tree[rc(k)].sine;
    tree[k].cosi = tree[lc(k)].cosi + tree[rc(k)].cosi;
}

// 和角化积公式
void formula(int k, double sinx, double cosx){
    double sina = tree[k].sine, cosa = tree[k].cosi;
    tree[k].sine = sina * cosx + cosa * sinx;
    tree[k].cosi = cosa * cosx - sina * sinx;
}

void push_down(int k){
    if(tree[k].tag != 0){
        double sinx = sin(tree[k].tag), cosx = cos(tree[k].tag);
        formula(lc(k), sinx, cosx);
        formula(rc(k), sinx, cosx);
        tree[lc(k)].tag += tree[k].tag;
        tree[rc(k)].tag += tree[k].tag;
        tree[k].tag = 0;
    }
}

void update(int lo, int hi, int x, int k = 1){
    if(lo <= tree[k].lo && tree[k].hi <= hi){
        formula(k, sin(x), cos(x));
        tree[k].tag += x;
        return;
    }
    push_down(k);
    int md = (tree[k].lo + tree[k].hi) / 2;
    if(lo <= md)
        update(lo, hi, x, lc(k));
    if(hi > md)
        update(lo, hi, x, rc(k));
    tree[k].sine = tree[lc(k)].sine + tree[rc(k)].sine;
    tree[k].cosi = tree[lc(k)].cosi + tree[rc(k)].cosi;
}

double query(int lo, int hi, int k = 1){
    if (lo <= tree[k].lo && tree[k].hi <= hi){
        return tree[k].sine;
    }
    push_down(k);
    double ans = 0;
    int md = (tree[k].lo + tree[k].hi) / 2;
    if (lo <= md)
        ans += query(lo, hi, lc(k));
    if (hi > md)
        ans += query(lo, hi, rc(k));
    return ans;
}

int n, m, op, a, b, c;
int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &v[i]);
    }
    build(1, n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++){
        scanf("%d", &op);
        if(op == 1){
            scanf("%d %d %d", &a, &b, &c);
            update(a, b, c);
        } else if (op == 2) {
            scanf("%d %d", &a, &b);
            printf("%.1lf\n", query(a, b));
        }
    }
    return 0;
}