#include <bits/stdc++.h>
#include <limits.h>

using namespace std;
#define MAXN 5005

int n, a, b;
int dp[MAXN];
pair<int, int> pt[MAXN]; 

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);        
        pt[i] = {a, b};
        dp[i] = 1;
    }
    sort(pt, pt + n);
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(pt[j].second < pt[i].second){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}