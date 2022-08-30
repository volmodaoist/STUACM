#include<bits/stdc++.h>
#include<limits>

using namespace std;

#define MAXN 300000
int n, a, b;
int ans;
int heads[MAXN], val[MAXN], nxt[MAXN], idx;
int vist[MAXN];

void add_edge(int a, int b){
    val[idx] = b;
    nxt[idx] = heads[a];
    heads[a] = idx++;
}


int dfs(int u){
    vist[u] = 1;
    int sum = 1, res = 0;
    for(int i = heads[u]; ~i; i = nxt[i]){
        int v = val[i];
        if(!vist[v]){
            int t = dfs(v);
            res = max(res, t);
            sum += t;
        }
    }
    res = max(res, n - sum);
    ans = min(ans, res);
    return sum;
}


int main(){
    scanf("%d", &n);
    memset(heads, -1, sizeof(heads));
    memset(vist, 0, sizeof(vist));
    
    ans = n;
    for(int i = 1; i < n; i++){
        scanf("%d %d", &a, &b);
        add_edge(a, b);
        add_edge(b, a);
    }
    
    dfs(1);
    printf("%d\n", ans);
    return 0;
}