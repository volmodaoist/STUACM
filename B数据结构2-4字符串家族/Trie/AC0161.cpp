#include <bits/stdc++.h>
#include <limits.h>

using namespace std;

#define MAXN 800005

char str[MAXN][30];
int sons[MAXN][15], cnt[MAXN], idx;

void insert(char str[]){
    int p = 0;
    for(int i = 0; str[i]; i++){
        int u = str[i] - '0';
        if(!sons[p][u]){
            sons[p][u] = ++idx;
        }
        p = sons[p][u];
    }
    cnt[p]++;
}

bool query(char str[]){
    int  p = 0;
    for(int i = 0; str[i]; i++){
        int u = str[i] - '0';
        if(cnt[p]) 
            return true;
        p = sons[p][u];
    }
    return cnt[p] >= 2;
}


// 使用字典树或者字符串哈希均可
int t, n, m, ok ;
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        
        idx = 0;
        memset(cnt, 0, sizeof(cnt));
        memset(sons, 0, sizeof(sons));
        
        bool ok = true;
        for(int i = 0; i < n; i++){
            scanf("%s", str[i]);
            insert(str[i]);
        }
        
        for(int i = 0; i < n; i++){
            if(query(str[i])){
                ok &= (!query(str[i]));
            }
        }
        printf("%s\n", (ok ? "YES":"NO"));
    }
    return 0;
}