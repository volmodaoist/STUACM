#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000010
int n, m;
int nxt[MAXN];
char s[MAXN], p[MAXN];

int main(){
    while(scanf("%d %s %d %s",&n, p+1, &m, s+1) != EOF){
        for(int i = 2, j = 0; i <= n; i++){
            while(j && p[i] != p[j + 1]) j = nxt[j];
            if(p[i] == p[j + 1]) j++;
            nxt[i] = j;
        }
        for(int i = 1, j = 0; i <= m; i++){
            while(j && s[i] != p[j + 1]) j = nxt[j];
            if(s[i] == p[j + 1]){
                j++;
            }
            if(j == n){
                printf("%d ", i - n);
                j = nxt[j];
            }
        }
    }    
    return 0;
}