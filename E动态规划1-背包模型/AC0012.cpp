#include<bits/stdc++.h>
using namespace std;

#define MAXN 1005
int n, m, v[MAXN], w[MAXN];
int dp[MAXN][MAXN], path[MAXN], idx;

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d %d", &v[i], &w[i]);
    for(int i = n; i >= 1; i--){
        for(int j = 0; j <= m; j++){
            dp[i][j] = dp[i + 1][j];
            if(j >= v[i]){
               dp[i][j] = max(dp[i][j], dp[i + 1][j - v[i]] + w[i]);
            }
        }
    }
    
    // 从小到大的遍历保证了最终存储的路径一定是字典序最小的
    for(int i = 1, j = m; i <= n; i++){
        if(j >= v[i] && dp[i][j] == dp[i + 1][j - v[i]] + w[i]){
            path[idx++] = i;
            j -= v[i];
        }
    }
    
    // 打印方案路径
    for(int i = 0; i < idx; i++){
        cout << path[i] << " ";
    }
    cout << endl;
    
    return 0;
}