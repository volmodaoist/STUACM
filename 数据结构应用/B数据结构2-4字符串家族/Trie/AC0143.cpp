#include<bits/stdc++.h>
using namespace std;

#define MAXN 3200010

int n, son[MAXN][2], arr[MAXN], idx;

// 第一个数位是符号位
void insert(int x){
    int p = 0;
    for(int i = 30; i >= 0; i--){
        int u = x >> i & 1;
        if(!son[p][u]){
            son[p][u] = ++idx;
        }
        p = son[p][u];
    }
}

int query(int x){
    int p = 0, ret = 0;
     for(int i = 30; i >= 0; i--){
        int u = x >> i & 1;
        if(son[p][!u]){
            p = son[p][!u];
            ret = 2 * ret + !u;
        }else{
            p = son[p][u];
            ret = 2 * ret + u;
        }
    }
    return ret;
}

int main(){
    while(scanf("%d", &n) != EOF){
        int ans = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
            insert(arr[i]);
            ans = max(ans, arr[i] ^ query(arr[i]));
        }
        printf("%d\n", ans);
    }
    return 0;
}