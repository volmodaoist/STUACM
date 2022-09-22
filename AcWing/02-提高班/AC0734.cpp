#include<bits/stdc++.h>
using namespace std;

typedef struct _Stone{
    int s, e, l;
    bool operator<(const struct _Stone other) const{
        return s * other.l < other.s * l;
    }
}Stone;

#define MAXN  10005

int dp[MAXN];
Stone stones[MAXN];

int kase;
int main(){
    scanf("%d", &kase);
    for(int k = 1; k <= kase; k++){
        int n = 0, m = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            int s, e, l;
            scanf("%d %d %d", &s, &e, &l);
            stones[i] = {s, e, l};
            m += s;
        }
        sort(stones, stones + n);
        
        // 此时所有时间的总和即为背包的容量，而且要注意背包容量定义为恰好装满，而非小于等于，
        // 因而这个时间的变化是跳跃式的，每次都增加s[i], 因而最大值不可能在个别离散时间点之间的中间状态取得，
        // 同时我们并不知道是在哪一个离散时间点取得的最大值，因而在最后我们仍然需要一趟遍历来确定哪一个是最大值！
        
        memset(dp, 0xcf, sizeof(dp));
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = m; j >=stones[i].s; j--){
                dp[j] = max(dp[j], dp[j - stones[i].s] + max(0, stones[i].e - (j - stones[i].s) * stones[i].l));
            }
        }
        int ans = 0;
        for(int i = 0; i <= m; i++){
            ans = max(ans, dp[i]);
        }
        printf("Case #%d: %d\n", k, ans);
    }
    return 0;
}