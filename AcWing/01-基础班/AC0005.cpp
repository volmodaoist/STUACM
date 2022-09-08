#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 3005
int n, m, v, w, s;
int dp[MAXN];

typedef struct good{
    int v, w;
}good;

vector<good> goods;

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d %d %d", &v, &w, &s);
        for(int k = 1; k <= s; k = k * 2){
            s -= k;
            goods.push_back({k * v, k * w});
        }
        if(s)goods.push_back({s * v, s * w});
    }
    for(auto &good: goods){
        for(int j = m; j >= good.v; j--){
            dp[j] = max(dp[j], dp[j - good.v] + good.w);
        }
    }
    printf("%d\n", dp[m]);
    return 0;
}