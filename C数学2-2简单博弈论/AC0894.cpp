#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 300

int n, x, memo[MAXN];

int sg(int x){
    if(memo[x] != -1){
        return memo[x];
    }
    unordered_set<int> ss;
    for(int i = 0; i < x; i++){
        for(int j = 0; j <= i; j++){
            ss.insert(sg(i) ^ sg(j));
        }
    }
    for(int i = 0; ; i++){
        if(!ss.count(i)){
            memo[x] = i; 
            break;
        }
    }
    return memo[x];
}

int main(){
    int ans = 0;
    scanf("%d", &n);
    memset(memo, -1, sizeof(memo));
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        ans = ans ^ sg(x);
    }
    printf("%s\n", ans ? "Yes" : "No");
    return 0;
}