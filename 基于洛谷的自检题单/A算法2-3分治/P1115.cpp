#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  MAXN  300005


int v[MAXN], n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    int ans = v[0], sumv = v[0];
    for (int i = 1; i < n; i++) {
        if(sumv < 0){
            sumv = 0;
        }
        sumv += v[i];
        ans = max(ans, sumv);
    }
    printf("%d\n", ans);
    return 0;
}