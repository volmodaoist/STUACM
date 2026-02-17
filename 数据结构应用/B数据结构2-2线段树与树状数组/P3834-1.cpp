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

typedef long long ill;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  MAXN  5500005
#define  MAXM  200005


// 此处维护的是左右子树的指针
typedef struct _TreeNode{
    int lc, rc;
    int s;
} TreeNode;

TreeNode tree[MAXN];
int root[MAXN], v[MAXM], idx;

void build(int lo, int hi, int &x){
    x = ++idx; 
    if (lo == hi) {
        return;
    }
    int md = (lo + hi) / 2;
    build(lo, md, tree[x].lc);
    build(md + 1, hi, tree[x].rc);
}

void update(int u, int &v, int lo, int hi, int val){
    v = ++idx, tree[v] = tree[u], tree[v].s++;
    if(lo == hi){
        return;
    }
    int md = (lo + hi) / 2;
    if(val <= md){
        update(tree[u].lc, tree[v].lc, lo, md, val);
    } else {
        update(tree[u].rc, tree[v].rc, md + 1, hi, val);
    }
}

int query(int u, int v, int lo, int hi, int k){
    if(lo == hi){
        return lo;
    }
    int md = (lo + hi) / 2;
    int s = tree[tree[v].lc].s - tree[tree[u].lc].s;
    if (k <= s) {
        return query(tree[u].lc, tree[v].lc, lo, md, k);
    } else {
        return query(tree[u].rc, tree[v].rc, md + 1, hi, k - s);
    }
}

int get_id(vector<int> &vec, int val){
    return lower_bound(vec.begin(), vec.end(), val) - vec.begin() + 1;
}


int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, m, a, b, k, id;
    scanf("%d %d", &n, &m);
    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        vec.push_back(v[i]);
    }
    sort(ALL(vec));
    vec.erase(unique(ALL(vec)), vec.end());
    int vmax = vec.size();

    // 其实这个空树建立与否都是可以的
    build(1, vmax, root[0]);

    for (int i = 1; i <= n; i++) {
        update(root[i - 1], root[i], 1, vmax, get_id(vec, v[i]));
    }
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &k);
        id = query(root[a - 1], root[b], 1, vmax, k) - 1;
        printf("%d\n", vec[id]);
    }
    return 0;
}