#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

int n, kase;

// https://codeforces.com/problemset/problem/1743/B
int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d", &kase);
    while(kase--){
        scanf("%d", &n);
        printf("1 ");
        for (int i = n - 1; i > 1; i--) {
            printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}