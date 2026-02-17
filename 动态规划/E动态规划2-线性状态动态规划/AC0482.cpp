#include <bits/stdc++.h>
#include <limits.h>

using namespace std;

#define MAXN 10005

int n;
int t[MAXN];
int f[MAXN], g[MAXN];


void debug_print_dp(int dp[MAXN]){
   for(int i = 1; i <= n; i++){
        printf("%d ", dp[i]);
    }
    printf("\n");
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &t[i]);
        f[i] = g[i] = 1;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(t[j] < t[i]){
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    for(int i = n; i >= 1; i--){
        for(int j = n; j > i; j--){
            if(t[j] < t[i]){
                g[i] = max(g[i], g[j] + 1);
            }
        }
    }
    
    
    // debug_print_dp(f);
    // debug_print_dp(g);
    
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, f[i] + g[i] - 1);
    }
    
    printf("%d\n", n - ans);
    return 0;
}