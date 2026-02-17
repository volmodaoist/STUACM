#include <bits/stdc++.h>
using namespace std;

#define MAXN 30005
int n, m, v, p, dp[MAXN];

int main(){
    scanf("%d %d", &m, &n);    
    for(int i = 0; i < n; i++){
        scanf("%d %d", &v, &p);
        for(int j = m; j >= v; j--){
            dp[j] = max(dp[j], dp[j - v] + v * p);
        }
    }
    
    cout << dp[m] << endl;
    return 0;
}