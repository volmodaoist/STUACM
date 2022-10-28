
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, x, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        ans = ans ^ x;
    }
    printf("%d\n", ans);
    return 0;
}