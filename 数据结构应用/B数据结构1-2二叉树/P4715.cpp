#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  MAXN  100005

#define  lc(x)  ((x << 1))
#define  rc(x)  ((x << 1)|1)

int tr[MAXN], idx[MAXN], n;

// 本题可作为zkw 线段树的基础
int main() {
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