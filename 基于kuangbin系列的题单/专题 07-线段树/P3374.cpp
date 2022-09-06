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


typedef long long Long;
typedef unsigned long long ULL;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  fi    first
#define  se    second

#define  MAXN  100005
#define lchild(x) (x << 1)
#define rchild(x) (x << 1 | 1)


int n, m, arr[500005], tr[2000010];

// k用于标记当前节点
inline void buildtree(int k, int lo, int hi){
    if(lo == hi){
        tr[k] = arr[lo];
        return;
    }
    int md = lo + (hi - lo) / 2;
    buildtree(2 * k, lo, md);
    buildtree(2 * k + 1, md + 1, hi);
    tr[k] = tr[2 * k] + tr[2 * k + 1];
}




inline void add(int k, int lo, int hi, int x, int c){
    tr[k] += c;
    if(lo == hi)
        return;
    int md = lo + (hi - lo) / 2;
    if(x <= md){
        add(2 * k, lo, md, x, c);
    }else{
        add(2 * k + 1, md + 1, hi, x, c);
    }
}

// 前三个参数用于控制范围, 查询区间[i,j]
inline int calc(int k, int lo, int hi, int i, int j){
    if(lo == i && hi == j){
        return tr[k]; // 当前区间完全覆盖待查区间的情况
    }
    int md = lo + (hi - lo) / 2;
    if(j <= md){   // 完全在左边
        return calc(2 * k, lo, md, i, j);
    }else if(i > md){ // 完全在右边
        return calc(2 * k + 1, md + 1, hi, i, j);
    }else{  // 横跨两边
        return calc(2 * k, lo, md, i, md) + calc(2 * k + 1, md + 1, hi, md + 1, j);
    }
}


int kase;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    while (scanf("%d %d", &n, &m) != EOF){
        for (int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
        }
        buildtree(1, 1, n);
        int op, a, b;
        for (int i = 1; i <= m; i++){
            scanf("%d %d %d", &op, &a, &b);
            if(op == 1){
                add(1, 1, n, a, b);
            }else{
                printf("%d\n", calc(1, 1, n, a, b));
            }
        }
    }

    return 0;
}