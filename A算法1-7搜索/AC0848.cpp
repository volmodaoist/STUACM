#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

#define MAXN 300000
int heads[MAXN], val[MAXN], nxt[MAXN], idx;
int d[MAXN];
int q[MAXN], hh, tt = -1;
int n, m, a, b;

void add_edge(int a, int b){
    val[idx] = b;
    nxt[idx] = heads[a];
    heads[a] = idx++;
}

bool bfs(){
    while(hh <= tt){
        int v, u  = q[hh++];
        for(int i = heads[u]; ~i; i = nxt[i]){
            v = val[i];
            d[v]--;
            if(d[v] == 0){
                q[++tt] = v;
            }
        }
    }
    return tt == n - 1;
}

int main(){
    scanf("%d %d", &n, &m);
    memset(heads, -1, sizeof(heads));
    
    for(int i = 1; i <= m; i++){
        scanf("%d %d", &a, &b);
        add_edge(a, b);
        d[b]++;
    }
    for(int i = 1; i <= n; i++){
        if(d[i] == 0){
            q[++tt] = i;
        }
    }
    
    if(bfs()){
        for(int i = 0; i <= tt; i++){
            printf("%d ", q[i]);
        }
    }else{
        printf("%d", -1);
    }
    printf("\n");
    return 0;
}