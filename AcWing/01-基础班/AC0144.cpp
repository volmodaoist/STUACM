#include <bits/stdc++.h>
#include <limits.h>

using namespace std;

#define MAXN 5000005

int head[MAXN], val[MAXN], nxt[MAXN], wgt[MAXN], link;
int sons[MAXN][2], cnt[MAXN], idx;
int arr[MAXN];

void add_edge(int u, int v, int w){
    val[idx] = v;
    wgt[idx] = w;
    nxt[idx] = head[u];
    head[u] = idx++;
}


void dfs(int u, int parent, int sum){
    arr[u] = sum;
    for(int i = head[u]; ~i; i = nxt[i]){
        int j = val[i];
        if(j != parent){
            dfs(j, u, sum ^ wgt[i]);
        }
    }
}

void insert(int x){
    int p = 0;
    for(int i = 30; i >= 0; i--){
        int u =  x >> i & 1;
        if(!sons[p][u]){
            sons[p][u] = ++idx;
        }
        p = sons[p][u];
    }
    cnt[p]++;
}

int query(int x){
    int p = 0, ans = 0;
    for(int i = 30; i >= 0; i--){
        int u =  x >> i & 1;
        if(sons[p][!u]){
            p = sons[p][!u];
            ans = 2 * ans + !u; 
        }else{
            p = sons[p][u];
            ans = 2 * ans + u;
        }
    }
    return ans;
}

int n, x;
int main(){
    memset(head, -1, sizeof(head));
    scanf("%d", &n);
    
    int a, b, w, ans = 0;
    for(int i = 0; i < n - 1; i++){
        scanf("%d %d %d", &a, &b, &w);
        add_edge(a, b, w);
        add_edge(b, a, w);

    }
    
    dfs(0, -1, 0);
    for(int i = 0; i < n ; i++){
        insert(arr[i]);
    }
    
    for(int i = 0; i < n ; i++){
        ans = max(ans, arr[i] ^ query(arr[i]));
    }
    printf("%d\n",ans);
    return 0;
}