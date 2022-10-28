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
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
#define  MAXN  200005


#define  lc(x)  (tree[x].lc)
#define  rc(x)  (tree[x].rc)
typedef struct _TreeNode{
    int lc, rc;
    int s;
}TreeNode;

TreeNode tree[MAXN << 5];
int v[MAXN], root[MAXN], idx;

// 由于引用操作只有cpp 能用，因而下面的板子通用性更好，也能适用于CLang
// 不过这种解法与前面一种解法没有本质差别，仅仅是运用的语法点不太一样而已，
int build(int lo, int hi){
    int x = ++idx;
    if(lo < hi){
        int md = (lo + hi) / 2;
        lc(x) = build(lo, md);
        rc(x) = build(md + 1, hi);
    }
    return x;
}

int update(int u, int lo, int hi, int val){
    int v = ++idx;
    tree[v] = tree[u], tree[v].s++;
    if(lo < hi){
        int md = (lo + hi) / 2;
        if(val <= md){
            lc(v) = update(lc(u), lo, md, val);   
        }else{
            rc(v) = update(rc(u), md + 1, hi, val);
        }
    }
    return v;
}

int query(int u, int v, int lo, int hi, int k){
    if(lo == hi){
        return lo;
    }
    int md = (lo + hi) / 2;
    int s = tree[lc(v)].s - tree[lc(u)].s;
    if (k <= s) {
        return query(lc(u), lc(v), lo, md, k);
    } else {
        return query(rc(u), rc(v), md + 1, hi, k - s);
    }
}

int get_id(vector<int> &vec, int val){
    return lower_bound(ALL(vec), val) - vec.begin() + 1;
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, m, a, b, k;
    scanf("%d %d", &n, &m);
    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        vec.push_back(v[i]);
    }

    sort(ALL(vec));
    vec.erase(unique(ALL(vec)), vec.end());
    int vmax = vec.size();

    root[0] = build(1, vmax);
    for (int i = 1; i <= n; i++){
        root[i] = update(root[i - 1], 1, vmax, get_id(vec, v[i]));
    }
    for (int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &k);
        printf("%d\n", vec[query(root[a - 1], root[b], 1, vmax, k) - 1]);
    }
    return 0;
}