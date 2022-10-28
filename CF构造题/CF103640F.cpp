#include <bits/stdc++.h>
#include <limits>
using namespace std;
 
 
typedef long long llong;
typedef unsigned long long ull;
#define  MAXN  500005
 
 
 
/**
 * 给定数据保证了所有对点之间都存在路径，并且是双向路径，
 * 然而不太明白本题给出的条件 "at most one road between each pair of fields"
 * 如果路径唯一，那这应该是一棵树？可是为啥样例允许 m > n,
 *
 *
 * 需要把给定图分割变成两个子图，可能是寻找割边、割点什么的（然而我记不住板子，’
 * 既然只有两个子集，那么并查集或许已经够用了，
 *  
 * 目前能够分析得出的有用信息:
 *  1.  第 i 块田地，产量等于 2^i，那这必不可能凑出两个人都相等的方案，
 *  2.  写出二进制表达式即可发现，2^i 大于 2^0 + 2^1 ... 2^(i-1) 所有项总和
 * 
 *  由于不可能相等的情况之下，A需要大于B，那么A拿地 第n个 顶点，然后B 再拿，第 n-1 个，
 * 接下来如果 B 能拿，也即拾取之后子图仍然连通则分给 B，反正 B 剩下的全拿也不可能大于 A 
*/
 
int pt[MAXN];
int find(int x) {
    return x != pt[x] ? pt[x] = find(pt[x]) : x;
}
 
int merge(int x, int y){
    int xr = find(x), yr = find(y);
    if(xr != yr){
        pt[xr] = pt[yr];
        return 1;
    }
    return 0;
}
 
 
int n, m, a, b;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
 
    while (cin >> n >> m){
        for (int i = 1; i <= n; i++)
            pt[i] = i;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            if (a == n || b == n)
                continue;
            merge(a, b);
        }
        for (int i = 1; i <= n; i++){
            if(find(i) == find(n - 1)){
                printf("%c", 'B');
            }else{
                printf("%c", 'A');
            }
        }
        cout << endl;
    }
 
    return 0;
}