#include<bits/stdc++.h>
using namespace std;

#define MAXN 100010
int son[MAXN][26], cnt[MAXN], idx;
char str[MAXN];

// 第零个节点是根节点也是空节点
void insert(char str[]){
    int p = 0;
    for(int i = 0;i < str[i]; i++){
        int u = str[i] - 'a';
        if(!son[p][u]){
            son[p][u] = ++idx;
        }
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char str[]){
    int p = 0;
    for(int i = 0; str[i]; i++){
        int u = str[i] - 'a';
        if(!son[p][u]){
            return 0;
        }
        p = son[p][u];
    }
    return cnt[p];
}

int n;
int main(){
    while(scanf("%d", &n) != EOF){
        char op[2];
        scanf("%s %s", op, str);
        if(op[0] == 'I'){
            insert(str);
        }else if(op[0] == 'Q'){
            printf("%d\n", query(str));
        }
    }
    return 0;
}