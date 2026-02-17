#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
typedef pair<int, int> ii;

vector<ii> edges[MAXN];
int d1[MAXN], d2[MAXN], d = 0;

void dfs(int u, int father){
    d1[u] = d2[u] = 0;
    for(auto &[v, w]: edges[u]){
        if(v == father)
            continue;
        dfs(v, u);
        int t = d1[v] + w;
        if(t > d1[u]){
            d2[u] = d1[u], d1[u] = t;
        }else if(t > d2[u]){
            d2[u] = t; 
        }
        d = max(d, d1[u] + d2[u]);
    }
}

int n, u, v, w;
int main(){
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        scanf("%d %d %d", &u, &v, &w);
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    dfs(1, 0);
    printf("%d\n", d);
    return 0;
}