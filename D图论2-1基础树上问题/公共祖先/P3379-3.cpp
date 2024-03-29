#include <bits/stdc++.h>
#include <limits>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  MAXN  500005

vector<int> edges[MAXN];
vector<ii> query[MAXN];
int ft[MAXN], vist[MAXN], ans[MAXN];
int n, m, s, a, b;

// tarjan算法计算最近公共祖先
int find(int x){
    return x != ft[x] ? (ft[x] = find(ft[x])) : ft[x];
}

void tarjan(int u){
    vist[u] = true;
    for(int v : edges[u]){
        if(!vist[v]){
            tarjan(v);
            ft[v] = u;
        }
    }
    for(auto q : query[u]){
        int v = q.first, i = q.second;
        if(vist[v]){
            ans[i] = find(v);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i < n;  i++){
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        query[a].push_back({b, i});
        query[b].push_back({a, i});
    }
    for (int i = 1; i <= n; i++){
        ft[i] = i;
    }
    tarjan(s);
    for (int i = 0; i < m; i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}