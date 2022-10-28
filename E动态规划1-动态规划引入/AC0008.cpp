#include<bits/stdc++.h>
using namespace std;

#define MAXN 1005
int n, V, v, M, m, w;
int dp[MAXN][MAXN];

int main(){
    scanf("%d %d %d", &n, &V, &M);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &v, &m, &w);
        for(int j = V; j >= v; j--){
            for(int k = M; k >= m; k--){
                dp[j][k] = max(dp[j][k], dp[j - v][k - m] + w);
            }
        }
    }
    cout << dp[V][M] << endl;
    return 0;
}