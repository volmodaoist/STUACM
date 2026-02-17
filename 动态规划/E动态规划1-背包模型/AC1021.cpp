#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 10005
typedef long long llong;

llong dp[MAXN];

int n, m, x;
int main(){
    scanf("%d %d", &n, &m);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        for(int j = x; j <= m; j++){
           dp[j] += dp[j - x];
        }
    }
    cout << dp[m] << endl;
    return 0;
}