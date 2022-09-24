
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




// 这是一道线段树模板题，但是利用数学式展开化简之后也能使用树状数组维护
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
            update(itr, i, (i - 1) * (arr[i] - arr[i - 1]));
           
        }


        int op, a, b, c;
        for (int i = 1; i <= m; i++){
            scanf("%d", &op);

            if(op == 1){
                scanf("%d %d %d", &a, &b, &c);
                
                b++;
                update(tr,    a,    c);
                update(tr,    b,   -c);
                update(itr,   a,    c * (a - 1));
                update(itr,   b,   -c * (b - 1));

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
