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

#define lc(x)  (tr[x].lc) 
#define rc(x)  (tr[x].rc) 
typedef struct _TreeNode{
    int lc, rc;
    int val, key, siz;
} TreeNode;

TreeNode tr[MAXN];
int v[MAXN], idx, root;

int new_node(int v){
    tr[++idx].val = v, tr[idx].key = rand(), tr[idx].siz = 1;
    return idx;
}

void push_up(int p){
    tr[p].siz = tr[lc(p)].siz + tr[rc(p)].siz + 1;
}

void split(int p, int v, int &x, int &y){
    if(!p){
        x = y = 0;
        return;
    }
    if(tr[p].val <= v){
        x = p; // 如果当前节点小于等于分裂标准，其左子树与右子树左侧的一小撮可能均满足此性质
        split(rc(x), v, rc(x), y);
    } else {
        y = p; // 如果当前节点严格大于分裂标准，其右子树与左子树右侧的一小撮可能均满足此性质
        split(lc(y), v, x, lc(y));
    }
    push_up(p);
}

int merge(int x, int y){
    if (!x || !y)  return x + y;
    if(tr[x].key < tr[y].key){
        rc(x) = merge(rc(x), y);
        push_up(x);
        return x;
    } else {
        lc(y) = merge(x, lc(y));
        push_up(y);
        return y;
    }
}

void ins(int v){
    int x, y, z;
    split(root, v, x, z);
    y = new_node(v);
    root = merge(merge(x, y), z);
}

void del(int v){
    int x, y, z;
    split(root, v, x, z), split(x, v - 1, x, y);
    y = merge(lc(y), rc(y));
    root = merge(merge(x, y), z);
}

int get_kth(int p, int k){
    if (k <= tr[lc(p)].siz){
        return get_kth(lc(p), k);
    } else if (k == tr[lc(p)].siz + 1) {
        return p;
    } else {
        return get_kth(rc(p), k - tr[lc(p)].siz - 1);
    }
}

int get_rank(int v){
    int x, y;
    split(root, v - 1, x, y);
    int ret = tr[x].siz + 1;
    root = merge(x, y);
    return ret;
}

// 因为约定左树小于等于，所以分裂要用 v - 1
int get_prev(int v){
    int x, y;
    split(root, v - 1, x, y);
    int p = get_kth(x, tr[x].siz);
    root = merge(x, y);
    return p;
}

// 因为约定右树严格大于，所以分裂使用 v 即可
int get_succ(int v){
    int x, y;
    split(root, v, x, y);
    int p = get_kth(y, 1);
    root = merge(x, y);
    return p;
}

int kase;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int op, x;
        scanf("%d %d", &op, &x);
        if (op == 1) ins(x);
        if (op == 2) del(x);
        if (op == 3) printf("%d\n", get_rank(x));
        if (op == 4) printf("%d\n", tr[get_kth(root, x)].val);
        if (op == 5) printf("%d\n", tr[get_prev(x)].val);
        if(op == 6) printf("%d\n", tr[get_succ(x)].val);
    }
    return 0;
}