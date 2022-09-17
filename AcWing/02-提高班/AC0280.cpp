#include <bits/stdc++.h>
using namespace std;

#define MAXN 105
#define MAXM 10005
int n, m, x, dp[MAXM];
int main(){
    scanf("%d %d", &n, &m);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        scanf("%d", &x);
        for(int j = m; j >= x; j--){
            dp[j] += dp[j - x];
        }
    }
    cout << dp[m] << endl;
    return 0;
}