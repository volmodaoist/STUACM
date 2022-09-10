#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 15 
#define MAXM 3000

typedef long long llong;


int even_zero[MAXM];         // 不允许存在奇数个数的连续位零
vector<int> valid_comb[MAXM]; // 存储合法的状态组合, 这个结构非常类似于邻接表

llong dp[MAXN][MAXM];

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m), n || m){
        for(int i = 0; i < 1 << n; i++){
            int ok = 1, cnt = 0;
            for(int j = 0; j < n; j++){
                if(i >> j & 1){
                    if(cnt & 1){
                        ok = 0;
                        break;
                    }
                    cnt = 0;
                }else cnt++;
            }
            if(cnt & 1) ok = false;
            even_zero[i] = ok;
        }
        
        
        for(int i = 0; i < 1 << n; i++){
            valid_comb[i].clear();
            for(int j = 0; j < 1 << n; j++){
                /** 
                  * 注意运算符优先级：乘除加减，移位比较，等值按位，逻辑问赋
                  * 如果状态(i,j) 之间不存在重叠位置并且组合在一起之后比特零是偶数，则可 i->j，
                  */
                if( ((i & j) == 0) && even_zero[ i | j]){
                    valid_comb[i].push_back(j);
                }
            }
        }
        
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1; i <= m; i++){
            for(int j = 0; j < (1 << n); j++){
                for(auto k: valid_comb[j]){
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }
        
        printf("%lld\n", dp[m][0]);   
    }
    return 0;
}