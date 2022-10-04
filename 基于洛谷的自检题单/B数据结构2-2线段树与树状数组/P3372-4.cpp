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


typedef long long llong;
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

int n, m, N = 1, v[MAXN];
llong tree[MAXN << 2], mark[MAXN << 2];


// 本题使用了 zkw 线段树，本题值得反复琢磨！
void build(){
    for (N = 1; N <= n; N <<= 1);
    for (int i = 1; i <= n; i++)
        tree[i + N] = v[i];
    for (int i = N - 1; i; --i){
        tree[i] = tree[lc(i)] + tree[rc(i)];
    }
}


void update(int lo, int hi, int val){
    int len = 1, cntl = 0, cnth = 0;
    for (lo += N - 1, hi += N + 1; lo ^ hi ^ 1; lo >>= 1, hi >>= 1, len <<= 1) {
        tree[lo] += cntl * val, tree[hi] += cnth * val;
        if(~lo & 1)
            tree[lo ^ 1] += val * len, mark[lo ^ 1] += val, cntl += len;
        if(hi & 1)
            tree[hi ^ 1] += val * len, mark[hi ^ 1] += val, cnth += len;
    }
    while(lo){
        tree[lo] += cntl * val, tree[hi] += cnth * val;
        lo >>= 1, hi >>= 1;
    }
}


llong query(int lo, int hi){
    llong ans = 0;
    int len = 1, cntl = 0, cnth = 0;
    for (lo += N - 1, hi += N + 1; lo ^ hi ^ 1; lo >>= 1, hi >>= 1, len <<= 1) {
        ans += cntl * mark[lo] + cnth * mark[hi];
        if (~lo & 1) ans += tree[lo ^ 1], cntl += len;
        if (hi & 1) ans += tree[hi ^ 1], cnth += len;
    }
    while(lo){
        ans += cntl * mark[lo] + cnth * mark[hi];
        lo >>= 1, hi >>= 1;
    }
    return ans;
}



int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%d", &v[i]);
    }
    build();
    
    int op, k, a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d", &op);
        if(op == 1){
            scanf("%d %d %d", &a, &b, &c);
            update(a, b, c);
        } else if (op == 2) {
            scanf("%d %d", &a, &b);
            printf("%lld\n", query(a, b));
        }
    }

    return 0;
}