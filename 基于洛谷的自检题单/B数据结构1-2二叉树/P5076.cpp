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

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  MAXN  100005


// 本题是一个平衡树的问题，由于BST代码非常冗长，我们通常使用集合来代替

int kase;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, op, x;
    scanf("%d", &n);
    multiset<int> ms;
    ms.insert(-2147483647);
    ms.insert(2147483647);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &op, &x);
        if(op == 1){
            auto pos = ms.lower_bound(x);
            int rank = 0;
            for (auto it = ms.begin(); it != pos; it++)
                rank++;
            printf("%d\n", rank);
        }else if(op == 2){
            auto it = ms.begin();
            for (int i = 1; i <= x; i++)
                it++;
            printf("%d\n", *it);
        }else if(op == 3){
            auto pos = ms.lower_bound(x);
            pos--;
            printf("%d\n", *pos);
        } else if (op == 4) {
            auto pos = ms.upper_bound(x);
            printf("%d\n", *pos);
        } else if (op == 5) {
            ms.insert(x);
        }
    }

    return 0;
}