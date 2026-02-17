#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

// 拉链法
#define N 100005

int head[N], elem[N], nxt[N], idx;

int insert(int x){
    int k = (x % N + N) % N;
    elem[idx] = x;
    nxt[idx] = head[k];
    head[k] = idx++;
}


bool find(int x){
    int k = (x % N + N) % N;
    for(int i = head[k]; ~i;  i = nxt[i]){
        if(elem[i] == x){
            return true;
        }
    }
    return false;
}

char op[3];

int n, x;
int main(){
    while(scanf("%d", &n) != EOF){
        memset(head, -1, sizeof(head));
        for(int i = 0; i < n; i++){
            scanf("%s %d", op, &x);
            if(op[0] == 'I'){
                insert(x);               
            }else if(op[0] == 'Q'){
                if(find(x)){
                    printf("Yes\n");
                }else{
                    printf("No\n");
                }
            }
        }
    }
    return 0;
}