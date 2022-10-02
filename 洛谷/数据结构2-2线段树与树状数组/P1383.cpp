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

#define  lc(x)  (tree[x].lc)
#define  rc(x)  (tree[x].rc)

typedef struct _TreeNode{
    int lo, hi, lc, rc;
    char val;
} TreeNode;

// 有点类似于可持久化数组，然而长度在变化，如果仅仅是插入倒也还行，但是不同于先前学过的 Trie，
// 本题最大的难点在于撤销操作会让数组变短，因而我们需要另开一个数组维护不同版本的数组的实际长度, 

int len[MAXN], root[MAXN], idx;
TreeNode tree[MAXN << 5];



void build(int lo, int hi, int &x){
    x = ++idx, tree[x].lo = lo, tree[x].hi = hi;
    if (lo == hi) {
        return;
    }
    int md = (lo + hi) / 2;
    build(lo, md, lc(x));
    build(md + 1, hi, rc(x));
}

void update(int u, int &v, int i, char val){
    v = ++idx, tree[v] = tree[u];
    if (tree[v].lo == tree[v].hi && tree[v].lo == i) {
        tree[v].val = val;
        return;
    }
    int md = (tree[v].lo + tree[v].hi) / 2;
    if(i <= md){
        update(lc(u), lc(v), i, val);
    } else {
        update(rc(u), rc(v), i, val);
    }
}

char query(int u, int i){
    if(tree[u].lo == tree[u].hi && tree[u].lo == i){
        return tree[u].val;
    }
    int md = (tree[u].lo + tree[u].hi) / 2;
    if(i <= md){
        return query(lc(u), i);
    } else {
        return query(rc(u), i);
    }
}

int main(){
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int t, m, n = 0;
    scanf("%d", &m);
    build(1, m, root[0]);
    for (int i = 0; i < m; i++) {
        char op[3], in[3];
        scanf("%s", op);
        if(op[0] == 'T'){
            scanf("%s", in);
            ++n;
            len[n] = len[n - 1] + 1;
            update(root[n - 1], root[n], len[n], in[0]);
        }else if(op[0] == 'U'){
            scanf("%d", &t);
            ++n;
            root[n] = root[n - t - 1];
            len[n] = len[n - t - 1];
        } else if (op[0] == 'Q') {
            scanf("%d", &t);
            printf("%c\n", query(root[n], t));
        }
    }

    return 0;
}