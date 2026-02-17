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
#define  MAXN  10005

int n, m, a, b, w;
vector<ii> edges[MAXN];
int dist[MAXN], cot[MAXN], inq[MAXN];

bool spfa(int s = 1){
    memset(dist, 0x3f, sizeof(dist));
    memset(cot, 0, sizeof(cot));
    memset(inq, 0, sizeof(inq));
    dist[s] = 0;
    queue<int> q; q.push(s); inq[s] = 1;
    while (q.size()) {
        int u = q.front(); q.pop(); inq[u] = 0;
        for(auto [w,v]: edges[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                cot[v] = cot[u] + 1;
                if (cot[v] >= n){
                    return true;
                }
                if(!inq[v]) q.push(v);
            };
        }
    }
    return false;
}

int kase;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d", &kase);
    while(kase--){
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++){
            edges[i].clear();
        }
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &a, &b, &w);
            if(w >= 0){
                edges[a].emplace_back(w, b);
                edges[b].emplace_back(w, a);
            }else{
                edges[a].emplace_back(w, b);
            }
        }
        if(spfa()){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}