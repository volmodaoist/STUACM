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
#include <limits>
using namespace std;


typedef long long llong;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
#define  fi    first
#define  se    second
#define  MAXN  1000005


/**
 * 本题来自于 2022 ICPC 网络赛，
 * 是说给定一个树，我们能对这棵树进行两种操作，
 *    第一种操作：shrink 是对仅有两个孩子的父节点删除并在两个孩子之间连起一条线
 *    第二种操作：delete 直接删掉某个节点
 * 只有删除会被计入操作次数，请问删掉这棵树的最少操作次数是多少
 * 
 * 
 * 
 *   本题采用贪心算法，能用 shrink 则用 shrink 实在用不了再用 delete，为什么贪心是正确的？
 * 
 *    首先 任何树节点如果度等于 1 或 0，那么这个节点仅能通过 delete 操作删除！
 *    显然 shrink 能在不增加操作次数的情况之下删掉一个节点，如果一个节点能用 shrink，但是我们使用 delete，
 * 其结果便是多增加了一次操作，而且 delete 删除节点之后不引入任何新连边，反而会使得很多树节点从互相联系变为
 * 彼此孤立，也就是说无法使得本不可使用 shrink 消除的节点变得能用 shrink 消除。也就是说，能用 shrink 则用
 * 操作则用 shrink 操作的策略至少不使得结果变得更差，因而我们先用 shrink 消除再用 delete 消除，会发现操作数
 * 等于树节点的叶子节点个数
 * 
 * 
 *   
 */ 


// 本题需要注意的细节：给定的树结构能够自由扭转选择根节点，且连边无方向，故不可以根据出入度计算叶子节点的个数
// 我们需要计算度等于零或者等于一的节点个数，也即叶子节点个数（特别地，如果 n = 1，那么唯一的这个节点既是叶节点也是根节点）

int kase, n, a, b;
int deg[MAXN];

int main() {
#ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d", &kase);
    while(kase--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            deg[i] = 0;

        // n nodes, n - 1 edges
        for (int i = 1; i < n; i++) {
            scanf("%d %d", &a, &b);
            deg[a]++, deg[b]++;
        }

        // debug_print_degree();
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if(deg[i] == 1){
                ans++;
            }
        }
        printf("%d\n", n <= 2 ? n : ans);
    }
    return 0;
}