#define _OJ_ONLINE_JUDGE_

#include <stdio.h>
#include <algorithm>
using namespace std;

#define  lc(x) (x << 1)
#define  rc(x) (x << 1 | 1)
#define  MAXN  400010

typedef long long ill;
typedef unsigned long long ull;

int n, m;

ill a, b, c;
ill ar[MAXN], tr[MAXN], tag[MAXN];

inline void buildtree(int k, int lo, int hi){
    if(lo == hi){
        tr[k] = ar[lo];
        return;
    }
    int md = lo + (hi - lo) / 2;
    buildtree(lc(k), lo, md);
    buildtree(rc(k), md + 1, hi);

    tr[k] = tr[lc(k)] + tr[rc(k)];
}



inline void update(int k, int lo, int hi, int i, int j, int c){
    if(i <= lo && hi <= j){
        tr[k] += (hi - lo + 1) * c;
        tag[k] += c;
        return;
    }
    int md = lo + (hi - lo) / 2;
    tag[lc(k)] += tag[k], tr[lc(k)] += tag[k] * (md - lo + 1);
    tag[rc(k)] += tag[k], tr[rc(k)] += tag[k] * (hi - md);
    tag[k] = 0;

    if(i <= md) update(lc(k), lo, md, i, j, c);
    if(j >  md) update(rc(k), md + 1, hi, i, j, c);

    tr[k] = tr[lc(k)] + tr[rc(k)];
}



inline ill query(int k, int lo, int hi, int i, int j){
    ill ans = 0;
    if(i <= lo && hi <= j){
        return tr[k];
    }
    int md = lo + (hi - lo) / 2;
    tag[lc(k)] += tag[k], tr[lc(k)] += tag[k] * (md - lo + 1);
    tag[rc(k)] += tag[k], tr[rc(k)] += tag[k] * (hi - md);
    tag[k] = 0;

    if(i <= md) ans += query(lc(k), lo, md, i, j);
    if(j > md)  ans += query(rc(k), md + 1, hi, i, j);
    return ans;
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    while (scanf("%d %d", &n, &m) != EOF){
        for (int i = 1; i <= n; i++){
            scanf("%lld", &ar[i]);
        }
        
        buildtree(1, 1, n);
        
        char op[3];

        for (int i = 1; i <= m; i++){
            scanf("%s", op);
            if(op[0] == 'Q'){
                scanf("%lld %lld", &a, &b);
                printf("%lld\n", query(1, 1, n, a, b));
            }else if(op[0] == 'C'){
                scanf("%lld %lld %lld", &a, &b, &c);
                update(1, 1, n, a, b, c);
            }
        }
    }

    return 0;
}