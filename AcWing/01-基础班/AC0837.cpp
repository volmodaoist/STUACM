#include<bits/stdc++.h>
using namespace std;

#define MAXN 100010

int p[MAXN],s[MAXN];

int find(int x){
    return x==p[x] ? x : p[x] = find(p[x]);
}

int merge(int a, int b){
    int ar = find(a);
    int br = find(b);
    if(ar != br){
        p[ar] = br;
        s[br] += s[ar];
    }
}

int n, m, a, b, x;
int main(){
    char op[3];
    while(scanf("%d %d", &n, &m) != EOF){
        for(int i = 0; i < n; i++)
            p[i] = i, s[i] = 1;
        for(int i = 0; i < m; i++){
            scanf("%s", op);
            if(strcmp(op, "C") == 0){
                scanf("%d %d", &a, &b);
                merge(a, b);
            }else if(strcmp(op, "Q1") == 0){
                scanf("%d %d", &a, &b);
                if(find(a) == find(b)){
                    printf("Yes\n");
                }else{
                    printf("No\n");
                }
            }else if(strcmp(op, "Q2") == 0){
                scanf("%d", &x);
                printf("%d\n", s[find(x)]);
            }
        }
    }
    return 0;
}