#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long ill;
typedef pair<int, int> ii;
#define  MAXN  100005


int n, a, b, t;
int ideg[MAXN], time_cost[MAXN], dist[MAXN];
vector<int> edges[MAXN];

void top_sort(){
    memset(dist, 0, sizeof(dist));
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if(!ideg[i]){
            dist[i] = time_cost[i];
            q.emplace(i);
        }
    }
    while(q.size()){
        int u = q.front(); q.pop();
        for (int v: edges[u]) {
            ideg[v]--;
            dist[v] = max(dist[v], dist[u] + time_cost[v]);
            if (ideg[v] == 0) {
                q.emplace(v);
            }
        }
    }
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d %d", &a, &t);
        time_cost[a] = t;
        while (scanf("%d", &b) && b != 0) {
            edges[b].emplace_back(a);
            ideg[a]++;
        }
    }
    
    // for (int u = 1; u <= n; u++){
    //     for(int v: edges[u]){
    //         printf("(u = %d, v = %d)\n", v, u);
    //     }
    // }


    top_sort();

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dist[i]);
    }
    printf("%d\n", ans);
    return 0;
}