#include<bits/stdc++.h>
using namespace std;

#define MAXN 1005
int hgt[MAXN], dp[MAXN], ep[MAXN];

int main(){
    int len = 1;
    while(cin >> hgt[len]) len++;
    
    for(int i = 1; i <= len; i++)
        dp[i] = 1, ep[i] = 1;
        
    for(int i = 1; i <= len; i++){
        for(int j = 1; j < i; j++){
            if(hgt[j] >= hgt[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }else{
                ep[i] = max(ep[i], ep[j] + 1);
            }
        }
    }
    
    /** 这里其实运用一个迪尔沃斯定理 Dilworth's theorem
     * 对于任意有限偏序集，其最大反链中元素的数目必等于最小链划分中链的数目
     * 其等价表述是说，对于一个有限序列，其最长不升子序列个数等于最长上升子序列长度，
     * 又或者说(对偶命题)：对于一个有限序列，其最长不降子序列个数等于最长下降子序列长度，
    */
   
    int ans1 = 0, ans2 = 2;
    for(int i = 1; i < len; i++){
        ans1 = max(ans1, dp[i]);
        ans2 = max(ans2, ep[i]);
    }
    cout << ans1 << endl;
    cout << ans2 << endl;
    
    return 0;
}