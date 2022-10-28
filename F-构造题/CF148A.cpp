#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define  MAXN  100005

int dragons[MAXN], k, l, m, n, d;

void hurt(int x){
    for (int i = x; i <= d; i += x) {
        dragons[i] |= 1;
    }
}

// https://codeforces.com/contest/148/problem/A
int main() {
    scanf("%d %d %d %d %d", &k, &l, &m, &n, &d);
    hurt(k);hurt(l);hurt(m);hurt(n);
    
    int ans = 0;
    for (int i = 1; i <= d; i++) {
        if(dragons[i]){
            ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}