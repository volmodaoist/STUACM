#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000

int n, v;
int vol[MAXN], wgt[MAXN];
int dp[MAXN];

int main(){
    scanf("%d %d", &n, &v);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &vol[i], &wgt[i]);
    }
    for(int i = 1; i <= n; i++){
        for(int j = v; j >= vol[i]; j--){
            dp[j] = max(dp[j], dp[j - vol[i]] + wgt[i]);
        } 
    }
    printf("%d\n", dp[v]);
    return 0;  
}