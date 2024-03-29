#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define  lc(x) (x << 1)
#define  rc(x) (x << 1 | 1)
#define  MAXN  400010

typedef long long ill;

int n, m;

ill a, b, c;
ill ar[MAXN], tr[MAXN];

inline void buildtree(int k, int lo, int hi){
    if(lo == hi){
        tr[k] = ar[lo];
        return;
    }
    int md = lo + (hi - lo) / 2;
    buildtree(lc(k), lo, md);
    buildtree(rc(k), md + 1, hi);

    tr[k] = max(tr[lc(k)], tr[rc(k)]);
}



inline void update(int k, int lo, int hi, int x, ill c){
    if(lo == hi){
        tr[k] = c;
        return;
    }
    int md = lo + (hi - lo) / 2;
    if(x <= md) update(lc(k), lo, md, x, c);
    if(x >  md) update(rc(k), md + 1, hi, x, c);

    tr[k] = max(tr[lc(k)], tr[rc(k)]);
}



inline ill query(int k, int lo, int hi, int i, int j){
    if(i <= lo && hi <= j){
        return tr[k];
    }
    int md = lo + (hi - lo) / 2;
    ill ans = 0;
    if(i <= md)  ans = max(ans, query(lc(k), lo, md, i, j));
    if(j >  md)  ans = max(ans, query(rc(k), md + 1, hi, i, j));
    return ans;
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    while (scanf("%d %d", &n, &m) != EOF){
        memset(ar, 0, sizeof(ar));
        memset(tr, 0, sizeof(tr));
        for (int i = 1; i <= n; i++){
            scanf("%lld", &ar[i]);
        }

        buildtree(1, 1, n);
        
        char op[3];

        for (int i = 1; i <= m; i++){
            scanf("%s", op);
            scanf("%lld %lld", &a, &b);
            if(op[0] == 'Q'){
                printf("%lld\n", query(1, 1, n, a, b));
            }else if(op[0] == 'U'){
                update(1, 1, n, a, b);
            }
        }
    }

    return 0;
}