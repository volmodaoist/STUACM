#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

int n, kase, p[100005];
void make_permutation(int n){
    int x = 1;
    for (int i = 1; i < n; i += 2) {
        p[i] = x++;
    }
    for (int i = 0; i < n; i += 2) {
        p[i] = x++;
    }
}

// https://codeforces.com/problemset/problem/1743/B
int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d", &kase);
    while(kase--){
        scanf("%d", &n);
        if (n % 2 == 0){
            make_permutation(n);
        } else {
            make_permutation(n - 1);
            p[n - 1] = n;
            swap(p[n - 1], p[n - 2]);
        }

        for (int i = 0; i < n; i++) {
            printf("%d ", p[i]);
        }
        printf("\n");
    }

    return 0;
}