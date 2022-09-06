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
#define  lc(x) (x << 1)
#define  rc(x) (x << 1 | 1)
#define  fi    first
#define  se    second
#define  MAXN  500005

typedef long long LLong;


// 维护tr与itr逻辑类似于维护差分数组
// 然而必须注意tr与itr是树状数组而非差分数组

int n, m, d;
LLong arr[MAXN], tr[MAXN], itr[MAXN];

inline int lowbit(int x){
    return (x & (-x));
}

inline void update(LLong tree[], int x, LLong c){
    for (int i = x; i <= n; i += lowbit(i)){
        tree[i] += c;
    }
}

inline LLong query(LLong tree[], int x){
    LLong ans = 0;
    for (int i = x; i; i -= lowbit(i)){
        ans += tree[i];
    }
    return ans;
}







int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    while (scanf("%d %d", &n, &m) != EOF){
        for (int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
        
            update(tr, i, arr[i]);
            update(tr, i + 1, -arr[i]);

            for (int j = 1; j <= n; j++){
                printf("%d ", tr[j]);
            }
            printf(", query = %d\n", query(tr, i));

            update(itr, i, (i - 1) * (arr[i] - arr[i - 1]));
           
        }


        int op, a, b, c;
        for (int i = 1; i <= m; i++){
            scanf("%d", &op);

            if(op == 1){
                scanf("%d %d %d", &a, &b, &c);
                
                b++;
                update(tr,  a,  c);
                update(tr,  b, -c);
                update(itr, a,  c * (a - 1));
                update(itr, b, -c * (b - 1));

            }else if(op == 2){
                scanf("%d %d", &a, &b);

                a--;
                LLong part1 = b * query(tr, b) - a * query(tr, a);
                LLong part2 = query(itr, b) - query(itr, a);

                printf("%lld\n", part1 - part2);
            }
        }
    }
    return 0;
}
