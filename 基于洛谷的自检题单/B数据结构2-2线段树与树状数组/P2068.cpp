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
#define  MAXN  100005


#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)

ill A[MAXN];
ill tree[MAXN << 2];
int n, w, a, b, pos, val, N = 1;

void build() {
    for (N = 1; N <= n; N <<= 1);
    for (int i = 1; i <= n; i++){
        tree[N + i] = A[i];
    }
    for (int i = N - 1; i; i--) {
        tree[i] = tree[lc(i)] + tree[rc(i)];
    }
}

void update(int x, int c){
    for (int i = N + x; i; i >>= 1){
        tree[i] += c;
    }
}

ill query(int lo, int hi){
    ill ans = 0;
    for (lo += N - 1, hi += N + 1; lo ^ hi ^ 1; lo >>= 1, hi >>= 1) {
        if (~lo & 1)
            ans += tree[lo ^ 1];
        if (hi & 1)
            ans += tree[hi ^ 1];
    }
    return ans;
}


int kase;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif


    char op[3];
    scanf("%d %d", &n, &w);
    build();
    for (int i = 0; i < w; i++) {
        scanf("%s", op);
        if (op[0] == 'x') {
            scanf("%d %d", &pos, &val);
            update(pos, val);
        } else if (op[0] == 'y') {
            scanf("%d %d", &a, &b);
            printf("%lld\n", query(a, b));
        }
    }
    return 0;
}