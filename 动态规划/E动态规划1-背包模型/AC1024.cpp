#include <bits/stdc++.h>
#include <limits.h>

#define MAXN 30000
using namespace std;

int v, n, x, dp[MAXN];
int main(){
    scanf("%d %d", &v, &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        for(int j = v; j >= x; j--){
            dp[j] = max(dp[j], dp[j - x] + x);
        }
    }
    cout << v - dp[v] << endl;
    return 0;
}