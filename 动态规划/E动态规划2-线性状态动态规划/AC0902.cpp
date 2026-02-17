#include<bits/stdc++.h>
using namespace std;

#define MAXN 1005
char a[MAXN];
char b[MAXN];

int n, m;
int dp[MAXN][MAXN];

void debug_print_dp(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            printf("%2d ", dp[i][j]);
        }
        printf("\n");
    }    
}

int main(){
    scanf("%d%s", &n, a + 1);
    scanf("%d%s", &m, b + 1);
    for(int i = 1; i <= n; i++) dp[i][0] = i; // b字符串为空，a 字符串仅能通过删除操作转为 b
    for(int j = 1; j <= m; j++) dp[0][j] = j; // a字符串为空，a 字符串仅能通过插入操作转为 b
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i - 1][j - 1];
            }else{
                /**
                 * 注意始终只对字符串 a 进行操作，目标是把 a 变成 b，
                 * dp[i][j] 代表使得 a[1,i] == b[1,j] 相同的最少操作次数，
                 * 我们对字符串 a[1, i] 进行状态划分，分为三种操作：增加、删除、修改，
                 * 如果需要增加操作才能等于 b[1, j]，说明经过变化，当前a[1,i]==b[1,j-1]，要在a末尾插入b[i],
                 * 如果需要删除操作才能等于 b[1, j]，说明经过变化，当前a[1,i-1]==b[i,j]，要把a末尾a[i]元素删除，
                 * 如果需要修改操作才能等于 b[1, j]，说明经过变化，当前a[1,i-1]==b[i,j-1]，再把a[i]换成b[i]即可，
                */ 
                dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
            }
        }
    }
    // debug_print_dp();
    printf("%d\n", dp[n][m]);
    return 0;
}