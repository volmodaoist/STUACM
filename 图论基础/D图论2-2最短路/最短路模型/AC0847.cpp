#include <bits/stdc++.h>
#include <limits>
using namespace std;

#define MAXN  300000
int heads[MAXN], val[MAXN], nxt[MAXN], idx;
int dist[MAXN], vist[MAXN];

int n, m, x, a, b;

void add_edge(int a, int b){
    val[idx] = b;
    nxt[idx] = heads[a];
    heads[a] = idx++;
}

int main(){
    scanf("%d %d", &n, &m);
    memset(heads, -1, sizeof(heads));
    memset(dist, -1, sizeof(dist));
    
    for(int j = 0; j < m; j++){
        scanf("%d %d", &a, &b);
        add_edge(a, b);
    }
    
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    

    while(!q.empty()){
        int len  = q.size(); 
        for(int k = 0; k < len; k++){
            int t = q.front(); q.pop(); 
            vist[t] = 1;
            for(int i = heads[t]; ~i; i = nxt[i]){
                int j = val[i];
                if(dist[j] == -1){
                    dist[j] = dist[t] + 1;
                    q.push(j);   
                }
            }
        }
    }
    printf("%d\n", dist[n]);
    return 0;
}