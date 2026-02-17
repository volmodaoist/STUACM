#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

// 开放寻址法
#define N    100005
#define INF  0x3f3f3f3f


int elem[N];

int find(int x){
    int k = (x % N + N) % N;
    while(elem[k] != INF && elem[k] != x){
        k++;
        if(k == N){
            k = 0; 
        }
    }
    return k;
}

char op[3];

int n, x;
int main(){
    while(scanf("%d", &n) != EOF){
        memset(elem, 0x3f, sizeof(elem));
        for(int i = 0; i < n; i++){
            scanf("%s %d", op, &x);
            if(op[0] == 'I'){
                elem[find(x)] = x;
            }else if(op[0] == 'Q'){
                if(elem[find(x)] != INF){
                    printf("Yes\n");
                }else{
                    printf("No\n");
                }
            }
        }
    }
    return 0;
}