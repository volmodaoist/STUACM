#include <bits/stdc++.h>
using namespace std;

#define MAXN 5005

int n;
int b[MAXN], dp[MAXN][2];
int path[MAXN];

// 二维数组，0 维护最长上升子序列，1 维护这个上升子序列和
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &b[i]);
        dp[i][0] = 1, dp[i][1] = b[i];
    }
    
    int ans = 0, idx = 0;
    memset(path, -1, sizeof(path));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(b[j] < b[i]){
                dp[i][0] = max(dp[i][0], dp[j][0] + 1);
                dp[i][1] = max(dp[i][1], dp[j][1] + b[i]);
            }
        }
        ans = max(ans, dp[i][1]); 
    }
    
    // debug 打印路径 
    // int curr = idx;
    // while(curr != -1){
    //     printf("b[%d] = %d\n", curr, b[curr]);
    //     curr = path[curr];
    // }
    
    cout << ans << endl;
    return 0;
}