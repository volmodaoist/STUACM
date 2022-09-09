#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

char str[MAXN][15];
char pat[MAXN];

int n, m, x;
int dp[MAXN][MAXN];

int edit_distence(char a[], char b[]){
    printf("函数内部: 0x%x, 内容:%s\n", a + 1, a + 1);
    int n = strlen(a + 1), m = strlen(b + 1); 
    for(int i = 1; i <= n; i++) dp[i][0] = i;
    for(int j = 1; j <= m; j++) dp[0][j] = j;
    
    for(int i = 1; i <= n;  i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i - 1][j - 1];
            }else{
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }
    }
    return dp[n][m];
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%s", str[i] + 1);
    }
    for(int i = 0; i < m; i++){
        int ans = 0;
        scanf("%s%d", pat + 1, &x);
        for(int j = 0; j < n; j++){
            // 如果传入参数写成 (str[j] + 1, pat + 1) 再在函数内部使用 strlen 计算字符串长度会出错
            printf("函数外部: 0x%x, 内容:%s\n", str[j] + 1, str[j] + 1);
            if(edit_distence(str[j], pat) <= x){
                ans++;
            }            
        }
        // printf("%d\n", ans);
        break;
    }
    
    return 0; 
}