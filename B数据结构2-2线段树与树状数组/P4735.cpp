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
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
#define  MAXN  600005

int v[MAXN], s[MAXN];
int ver[MAXN << 5], root[MAXN << 5], son[MAXN << 5][2], idx;

// 使用 u 记录先前版本的树节点，使用 v 记录当前版本树节点 
void insert(int u, int v, int i) {
    ver[v] = i;
    for (int k = 30; k >= 0; k--){
        int c = s[i] >> k & 1;
        son[v][!c] = son[u][!c];        // 若非新节点则挂接连在先前版本节点
        son[v][c] = ++idx;              // 若是新节点则新开一个当前版本节点
        u = son[u][c], v = son[v][c];
        ver[v] = i;        
    }
}

// 使用 u 记录当前版本的根节点，u 能够移到先前的、版本号大于等于L版本对应的节点
int query(int u, int lo, int val){
    int ans = 0;
    for (int k = 30; k >= 0; k--){
        int c = val >> k & 1;
        if (ver[son[u][!c]] >= lo){
            u = son[u][!c];
            ans += 1 << k;
        } else {
            u = son[u][c];
        }
    }
    return ans;
}


int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, m, a, b, x;
    scanf("%d %d", &n, &m);

    // 给定问题转为前缀和问题之后等价于查找一个 p-1 in [L-1,R-1]，使其固定值 s[n]^x 最大即可
    // 我们使用零代表空节点，如果左边界等于 1，此时 L - 1 = 0，如果ver[0]不舍为零，则在 query 过程会走到空节点

    ver[0] = -1, root[0] = ++idx;
    insert(0, root[0], 0);

    // 使用索引作为版本号，每插入一个数据相当于新开一个版本
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        root[i] = ++idx;
        s[i] = s[i - 1] ^ v[i];
        insert(root[i - 1], root[i], i);
    }

    char op[3];
    while (m--) {
        scanf("%s", op);
        if(op[0] == 'A'){
            scanf("%d", &x);
            ++n;
            v[n] = x, root[n] = ++idx;
            s[n] = s[n - 1] ^ x;
            insert(root[n - 1], root[n], n);
        } else if (op[0] == 'Q') {
            scanf("%d %d %d", &a, &b, &x);
            printf("%d\n", query(root[b - 1], a - 1, s[n] ^ x));
        }
    }
    return 0;
}