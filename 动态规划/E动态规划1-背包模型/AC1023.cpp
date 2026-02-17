#include<bits/stdc++.h>
using namespace std;

#define MAXN 3000

int n;
int cost[4] = {10, 20, 50, 100};
int dp[MAXN];

int main(){
    scanf("%d", &n);
    dp[0] = 1;
    for(int i = 0; i < 4; i++){
        for(int j = cost[i]; j <= n; j++){
            dp[j] += dp[j - cost[i]];
        }
    }
    cout << dp[n] << endl;
    return 0;
}