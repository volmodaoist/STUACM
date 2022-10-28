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
#define  MAXN  100005


// 允许重复元素存在
typedef struct _TreeNode{
    int v, p, s[2];
    int siz, cnt;
} TreeNode;

int root, idx;
TreeNode tr[MAXN];

int new_node(int p, int v){
    tr[++idx].v = v, tr[idx].p = p, tr[idx].siz = tr[idx].cnt = 1;
    return idx;
}

void push_up(int x){
    tr[x].siz = tr[tr[x].s[0]].siz + tr[tr[x].s[1]].siz + tr[x].cnt;
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

int get_prev(int v){
    int x = find(v);
    if (tr[x].v < v) {
        return x;
    }
    x = tr[x].s[0];
    while (tr[x].s[1]) x = tr[x].s[1];
    return x;
}

int get_succ(int v){
    int x = find(v);
    if (tr[x].v > v){
        return x;
    }
    x = tr[x].s[1];
    while(tr[x].s[0]) x = tr[x].s[0];
    return x;
}


// 务必注意括号运算符里面比较运算是否正确！
void ins(int v){
    int x = root, p = 0;
    while(x && tr[x].v != v){
        p = x, x = tr[x].s[v > tr[x].v];
    }
    if(x){
        tr[x].cnt++;
    }else{
        x = new_node(p, v);
        tr[p].s[v > tr[p].v] = x;
    }
    splay(x, 0);
}

// 直接删除比较麻烦，因而先找前驱和后继，利用它们把待删除的节点夹到叶子节点，
// 又因为最小值无前驱，最大值无后继，为了减少特判，简化代码，故在树中插入正负无穷大作为哨兵，
void del(int v){
    int prev = get_prev(v);
    int succ = get_succ(v);
    splay(prev, 0), splay(succ, prev);
    int temp = tr[succ].s[0];
    if(tr[temp].cnt > 1){
        tr[temp].cnt--, splay(temp, 0);
    }else{
        tr[succ].s[0] = 0, splay(succ, 0);
    }
}

// 由于左右子树分别存在负无穷、正无穷哨兵，因而查找元素排在第几名的的时候无需进行+1操作
int get_rank(int v){
    return tr[tr[find(v)].s[0]].siz;
}

int get_val(int k){
    int x = root;
    while(1){
        int s = tr[x].s[0];
        if(tr[s].siz + tr[x].cnt < k){
            k -= tr[s].siz + tr[x].cnt;
            x = tr[x].s[1];
        }else if(tr[s].siz >= k){
            x = tr[x].s[0];
        }else break;
    }
    splay(x, 0);
    return tr[x].v;
}






int kase;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n;
    ins(-2e9), ins(2e9);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int op, x;
        scanf("%d %d", &op, &x);
        if (op == 1) ins(x);
        if (op == 2) del(x);
        if (op == 3) printf("%d\n", get_rank(x));
        if (op == 4) printf("%d\n", get_val(x + 1));
        if (op == 5) printf("%d\n", tr[get_prev(x)].v);
        if (op == 6) printf("%d\n", tr[get_succ(x)].v);
    }
    return 0;
}