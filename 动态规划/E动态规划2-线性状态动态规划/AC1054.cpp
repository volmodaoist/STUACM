#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
int n, s[MAXN], prec[MAXN], last[MAXN];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &s[i]);
    }
    prec[0] = INT_MAX;
    last[n + 1] = INT_MIN;
    
    // 维护前项最小值
    for(int i = 1; i <= n; i++){
        prec[i] = min(prec[i - 1], s[i]);
    }
    
    // 维护后项最大值
    for(int i = n; i >= 1; i--){
        last[i] = max(last[i + 1], s[i]);
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, last[i] - prec[i]);
    }
    printf("%d\n", ans);
    return 0;
}