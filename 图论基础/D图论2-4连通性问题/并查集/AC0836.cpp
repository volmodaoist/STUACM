#include<bits/stdc++.h>
using namespace std;

#define MAXN 100010

int p[MAXN];
int find(int x){
    return x==p[x] ? x : p[x] = find(p[x]);
}
int merge(int a, int b){
    int ar = find(a);
    int br = find(b);
    if(ar != br){
        p[ar] = br;
    }
}

int n, m, a, b;
int main(){
    char op[2];
    while(scanf("%d %d", &n, &m) != EOF){
        for(int i = 0; i < n; i++)
            p[i] = i;
        for(int i = 0; i < m; i++){
            scanf("%s %d %d", op, &a, &b);
            if(op[0] == 'M'){
                merge(a, b);
            }else if(op[0] == 'Q'){
                if(find(a) == find(b)){
                    printf("Yes\n");
                }else{
                    printf("No\n");
                }
            }
        }
    }
    return 0;
}