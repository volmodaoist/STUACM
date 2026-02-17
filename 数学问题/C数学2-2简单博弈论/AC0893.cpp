#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 10005

int x, k, n;
int nums[MAXN], memo[MAXN];
int sg(int x){
    if(memo[x] != -1){
        return memo[x];
    }
    unordered_set<int> ss;
    for(int i = 0; i < k; i++){
        if(x >= nums[i]){
            ss.insert(sg(x - nums[i]));
        }
    }
    for(int i = 0 ;  ; i++){
        if(!ss.count(i)){
            memo[x] = i;
            break;
        }
    }
    return memo[x];
}


int main(){
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf("%d", &nums[i]);
    }
    
    scanf("%d", &n);
    memset(memo, -1, sizeof(memo));
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        ans = ans ^ sg(x);
    }
    printf("%s\n", ans ? "Yes" : "No");
    return 0;
}