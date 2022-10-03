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


// 标签永久化思想
typedef struct _TreeNode{
    int lo, hi;
    llong val, tag;
} TreeNode;

TreeNode tr[MAXN];
int v[MAXN], cnt = 0;

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

// 如果更新区间恰好等于当前树节点维护的区间，则把元素加到标签上面，否则加到数值上面
void update(int lo, int hi, int c, int k = 1) {
    if (tr[k].lo == lo && tr[k].hi == hi) {
        tr[k].tag += c;
        return;
    }
    tr[k].val += (hi - lo + 1) * c;
    int md = (tr[k].lo + tr[k].hi) / 2;
    
    // 下列的更新操作的 hi <= md 与 lo > md 看起来有点诡异，但是这里的 md 是指树节点维护区间的中值，lo、hi 是更新区间的两端
    if (hi <= md) {
        update(lo, hi, c, lc(k));
    }else if(lo > md){
        update(lo, hi, c, rc(k));
    } else {
        update(lo, md, c, lc(k)), update(md + 1, hi, c, rc(k));
    }
}


// 使用一个变量在递归过程中传递一下树上路径的标签和，
// 标签永久化之后甚至都不需要存数值，只要存标签即可，建树的过程改用 update 实现（虽然这样复杂度会更高一点
llong query(int lo, int hi, llong c, int k = 1){
    c += tr[k].tag; 
    if(tr[k].lo == lo && tr[k].hi == hi){
        return tr[k].val + c * (hi - lo + 1);
    }
    int md = (tr[k].lo + tr[k].hi) / 2;

    // 同理于 update 操作中，此处的 lo、hi 是查询区间的两端，md 是指树节点维护区间的中值，二者描述的主体不一样
    if (hi <= md) {
        return query(lo, hi, c, lc(k));
    } else if (lo > md) {
        return query(lo, hi, c, rc(k));
    }else{
        return query(lo, md, c, lc(k)) + query(md + 1, hi, c, rc(k));
    }
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%d", &v[i]);
    }

    build(1, n);
    int op, k, a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d", &op);
        if(op == 1){
            scanf("%d %d %d", &a, &b, &c);
            update(a, b, c);
        } else if (op == 2) {
            scanf("%d %d", &a, &b);
            printf("%lld\n", query(a, b, 0LL));
        }
    }

    return 0;
}