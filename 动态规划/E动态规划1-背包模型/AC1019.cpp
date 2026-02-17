#include<bits/stdc++.h>
using namespace std;

int n, m, v, w, s;
int dp[8000];

int main(){
    scanf("%d %d", &n, &m);

    // 零一背包能够逆序遍历，优化去掉一个维度
    for(int i = 1; i <= n; i++){
        scanf("%d %d %d", &v, &w, &s);
        for(int j = m; j >= 0; j--){
            for(int k = 0; k <= s; k++){
                if(j >= k * v){
                    dp[j] = max(dp[j], dp[j - k * v] + k * w);   
                }
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}