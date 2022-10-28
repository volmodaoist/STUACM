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
#include <limits.h>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  MAXN  500005

typedef struct _Item{
    int val, idx;
    bool operator<(const struct _Item &item) const{
        if(val != item.val){
            return val < item.val;
        }else{
            return idx < item.idx;
        }
    }
}Item;

Item items[MAXN];

ill n, tr[MAXN];
inline int lowbit(int x) {
    return x & (-x);
}

inline ill query(int x){
    ill ans = 0;
    for (int i = x; i; i -= lowbit(i)) {
        ans += tr[i];
    }
    return ans;
}

inline void update(int x, int c){
    for (int i = x; i <= n; i += lowbit(i)) {
        tr[i] += c;
    }
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    
    ill ans = 0;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &items[i].val);
        items[i].idx = i;
    }

    stable_sort(items + 1, items + n + 1);
    for (int i = 1; i <= n; i++){
        update(items[i].idx, 1);
        ans += query(items[i].idx);
    }
    // 所有可能构成的序对减掉顺序序对、等序对，剩下的就是逆序对
    if(n & 1){
        printf("%lld\n", 1LL * (n + 1) / 2 * n - ans);
    } else {
        printf("%lld\n", 1LL * n / 2 * (n + 1) - ans);
    }
    return 0;
}