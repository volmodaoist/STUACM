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


#define  lc(x)  (tr[x].lc)
#define  rc(x)  (tr[x].rc)
typedef struct _TreeNode{
    int lc, rc;
    int val, key, siz, tag;
} TreeNode;

int root, idx;
TreeNode tr[MAXN];

int new_node(int v){
    tr[++idx].val = v, tr[idx].key = rand(), tr[idx].siz = 1, tr[idx].tag = 0;
    return idx;
}


void push_up(int p){
    tr[p].siz = tr[lc(p)].siz + tr[rc(p)].siz + 1;
}

void push_down(int p){
    if (p && tr[p].tag){
        swap(lc(p), rc(p));
        tr[lc(p)].tag ^= 1;
        tr[rc(p)].tag ^= 1;
        tr[p].tag = 0;
    }
}


// 普通FHQ Treap按照元素值分裂，文艺FHQ Treap按照排名分裂
void split(int p, int k, int &x, int &y){
    if(!p){
        x = y = 0;
        return;
    }
    push_down(p);
    if(k > tr[lc(p)].siz){
        k -= tr[lc(p)].siz + 1;
        x = p;
        split(rc(p), k, rc(p), y);
    } else {
        y = p;
        split(lc(p), k, x, lc(p));
    }
    push_up(p);
}



int merge(int x, int y){
    if(!x || !y)
        return x + y;
    if(tr[x].key < tr[y].key){
        push_down(x), rc(x) = merge(rc(x), y);
        push_up(x);
        return x;
    } else {
        push_down(y), lc(y) = merge(x, lc(y));
        push_up(y);
        return y;
    }
}

void output(int p){
    if(p){
        push_down(p);
        output(lc(p));
        printf("%d ", tr[p].val);
        output(rc(p));
    }
}

void reverse(int lo, int hi){
    int x, y, z;
    split(root, hi, x, z);
    split(x, lo - 1, x, y);
    tr[y].tag ^= 1;
    root = merge(merge(x, y), z);
}



int kase;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, m, a, b;
    srand(time(0));
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        root = merge(root, new_node(i));
    }
    while (m--) {
        int x, y, z;
        scanf("%d %d", &a, &b);
        reverse(a, b);
    }
    output(root);


    return 0;
}