#include<bits/stdc++.h>
using namespace std;

#define MAXN 1005
int hgt[MAXN], dp[MAXN], ep[MAXN];

int main(){
    int len = 0;
    while(cin >> hgt[len]) len++; 
    // 千万别把len++写进判断，否则跳出循环的那一次判断会导出 len 多加一次
    
    int ans = 0;
    for(int i = 0; i < len; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(hgt[j] >= hgt[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    
    // 贪心算法分组, 当前元素身后要尽可能接一个较大的
    // 这里相当于分组，每个ep相当于一个分组，维护一个非严格单调递减序列
    int cnt = 0;
    for(int i = 0; i < len ; i++){
        int k = 0;
        while(k < cnt && ep[k] < hgt[i])
            k++;
        if(k >= cnt){
            cnt++;
        }
        ep[k] = hgt[i];
    }
    cout << cnt << endl;
    
    return 0;
}