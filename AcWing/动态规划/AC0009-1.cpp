#include <bits/stdc++.h>
#include <limits.h>

using namespace std;
typedef pair<int, int> ii;
typedef struct good{
    int v, w;
}good;

#define MAXN 1000

int n, m, v, w, s;
int dp[MAXN][MAXN];
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
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = dp[i - 1][j];
            for(int  k = 0; k < goods[i].size(); k++){
                if(j >= goods[i][k].v){
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - goods[i][k].v] + goods[i][k].w);   
                }
            }
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;
}

