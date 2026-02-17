#include <bits/stdc++.h>
#include <limits.h>

using namespace std;
typedef pair<int, int> ii;
typedef struct good{
    int v, w;
}good;

#define MAXN 1000

int n, m, v, w, s;
int dp[MAXN];
vector<good> goods[MAXN];

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n ; i++){
        scanf("%d", &s);
        for(int k = 0; k < s; k++){
            scanf("%d %d", &v, &w);
            goods[i].push_back({v, w});
        }
    }

    // 参考零一背包的思路优化本题
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= 0; j--){
            for(int  k = 0; k < goods[i].size(); k++){
                if(j >= goods[i][k].v){
                    dp[j] = max(dp[j], dp[j - goods[i][k].v] + goods[i][k].w);   
                }
            }
        }
    }
    printf("%d\n", dp[m]);
    return 0;
}