#include <bits/stdc++.h>
#include <limits.h>

using namespace std;

#define MAXN 100005
char str[1000005];
int sons[MAXN][30], cnt[MAXN], idx;

void insert(char str[]){
    int p = 0;
    for(int i = 0; str[i]; i++){
        int u = str[i] - 'a';
        if(!sons[p][u]){
            sons[p][u] = ++idx;
        }
        p = sons[p][u];
    }
    cnt[p]++;
}

int query(char str[]){
    int  p = 0, ans = 0;
    for(int i = 0;  str[i]; i++){
        int u = str[i] - 'a';
        if(!sons[p][u]){
            return ans;
        }
        p = sons[p][u], ans += cnt[p];
    }
    return ans;
}

int n, m;
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%s", str);
        insert(str);
    }
    for(int i = 0; i < m; i++){
        scanf("%s", str);
        printf("%d\n", query(str));
    }
    return 0;
}