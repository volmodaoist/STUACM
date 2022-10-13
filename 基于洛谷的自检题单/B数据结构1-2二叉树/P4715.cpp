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

#define  lc(x)  ((x << 1))
#define  rc(x)  ((x << 1)|1)

int tr[MAXN], idx[MAXN];

// 本题可作为zkw 线段树的基础
int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n;
    scanf("%d", &n);
    int base = 1 << n;
    for (int i = 0; i < base; i++){
        scanf("%d", &tr[base + i]);
        idx[base + i] = base + i;
    }

    for (int i = base - 1; i >= 1; i--){
        if(tr[lc(i)] > tr[rc(i)]){
            tr[i] = tr[lc(i)];
            idx[i] = idx[lc(i)];
        }else{
            tr[i] = tr[rc(i)];
            idx[i] = idx[rc(i)];
        }
    }

    // tr[1]便是冠军，tr[1]左右孩子里面某一个是亚军，找出较小的那一个
    int ans = 0;
    if (tr[2] < tr[3]) {
        ans = idx[2];
    } else {
        ans = idx[3];
    }
    printf("%d\n", ans - base + 1);
    return 0;
}