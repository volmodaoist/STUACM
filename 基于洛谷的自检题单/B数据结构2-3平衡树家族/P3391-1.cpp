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


// 允许重复元素存在
typedef struct _TreeNode{
    int v, p, s[2];
    int siz,tag;
    void init(int p0, int v0) { 
        v = v0, p = p0, siz = 1, tag = 0;
    }
} TreeNode;

TreeNode tr[MAXN];
int root, idx, n, m, x, a, b;

void push_up(int x){
    tr[x].siz = tr[tr[x].s[0]].siz + tr[tr[x].s[1]].siz + 1;
}

void push_down(int x){
    if(tr[x].tag){
        swap(tr[x].s[0], tr[x].s[1]);
        tr[tr[x].s[0]].tag ^= 1;
        tr[tr[x].s[1]].tag ^= 1;
        tr[x].tag = 0;
    }
}

/**
 * 变量 ci、bi、di 分别代表此端、彼端、顶端，
 * 例如 x 如果位于左端，此端即左端，彼端即右端，反之此端为右端，彼端为左端，
 * 顶端是指 x 父节点 y 挂在祖先节点 z 哪一侧 (x <- y <- z)，0 代表左侧，1 代表右侧!
*/
void rotate(int x){
    int y = tr[x].p, z = tr[y].p;
    int ci = tr[y].s[1] == x, di = tr[z].s[1] == y, bi = ci ^ 1;

    int t = tr[x].s[bi];
    tr[y].s[ci] = t, tr[t].p = y;
    tr[x].s[bi] = y, tr[y].p = x;
    tr[z].s[di] = x, tr[x].p = z;

    // 自顶向上更新信息
    push_up(y), push_up(x);
}

/** 
 * 伸展操作访问节点 x, 并把 x 转到根节点，此处我们虚设 0 作为根节点的父节点
 *    如果 k > 0 则把 x 转到 k 子节点位置，
 *    如果 k = 0 则把 x 转到 root 根节点位置，
*/
void splay(int x, int k){
    while (tr[x].p != k){
        int y = tr[x].p, z = tr[y].p;
        if (z != k){
            (tr[y].s[0] == x) ^ (tr[z].s[0] == y) 
                ? rotate(x) : rotate(y);
        }
        rotate(x);
    }
    if(k == 0) root = x;
}

/**
 * 查找 v 所在节点并把这个节点转到根节点，
 * 之所以要做这趟旋转，是因为如果这个节点不存在，那么退出 find 函数的时候，
 * 此时 x 指向的位置非常最接近 v，这条性质能够帮助我们快速计算这个元素的前驱或后继！
*/
int find(int v){
    int x = root;
    while (tr[x].s[v > tr[x].v] && v != tr[x].v){
        x = tr[x].s[v > tr[x].v];
    }
    splay(x, 0);
    return root;
}

int get_kth(int k){
    int x = root;
    while(1){
        push_down(x);
        int s = tr[x].s[0];
        if(tr[s].siz + 1 < k){
            k -= tr[s].siz + 1;
            x = tr[x].s[1];
        }else if(tr[s].siz >= k){
            x = tr[x].s[0];
        }else break;
    }
    return x;
}

// 务必注意括号运算符里面比较运算是否正确！
void insert(int v){
    int x = root, p = 0;
    while(x && tr[x].v != v){
        p = x, x = tr[x].s[v > tr[x].v];
    }
    x = ++idx;
    tr[p].s[v > tr[p].v] = x;
    tr[x].init(p, v);
    splay(x, 0);
}


void output(int x) {
    push_down(x);
    if(tr[x].s[0]) output(tr[x].s[0]);
    if(tr[x].v >= 1 && tr[x].v <=n){
        printf("%d ", tr[x].v);
    }
    if(tr[x].s[1]) output(tr[x].s[1]);
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif


    insert(-2e9), insert(2e9);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        insert(i);
    }
    while (m--) {
        scanf("%d %d", &a, &b);
        a = get_kth(a), b = get_kth(b + 2);
        splay(a, 0), splay(b, a);
        tr[tr[b].s[0]].tag ^= 1;
    }
    output(root);
    return 0;
}