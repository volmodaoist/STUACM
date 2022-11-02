#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define  MAXN  6000005

int n, L, R, arr[MAXN];
int dp[MAXN], deq[MAXN], head, tail = -1;

int main() {
    scanf("%d %d %d", &n, &L, &R);
    memset(dp, 0x80, sizeof(dp));
    for (int i = 0; i <= n; i++){
        scanf("%d", &arr[i]);
    }

    dp[0] = 0;
    int ans = -2e9;
    for (int i = L; i <= n; i++) {
        while (head <= tail && dp[i - L] >= dp[deq[tail]]) {
            tail--;
        }
        deq[++tail] = i - L;
        while (head <= tail && deq[head] < i - R) {
            head++;
        }
        dp[i] = dp[deq[head]] + arr[i];
        if(i + R > n){
            ans = max(ans, dp[i]);
        }
    }
    printf("%d\n", ans);
    return 0;
}