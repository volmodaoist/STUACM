#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))

#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
typedef pair<int, int> ii;
#define	 INF   2147483647
#define  MAXN  10005


int n, m, s, a, b, w;
vector<ii> edges[MAXN];
int vist[MAXN], dist[MAXN];

void dijstra(int s){
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    for (int i = 1; i < n; i++) {
        int t = 0;
        for (int j = 1; j <= n; j++){
            if(!vist[j] && dist[j] < dist[t]){
                t = j;
            }
        }
        vist[t] = 1;
        for(auto[w, v]: edges[t]){
            if(dist[v] > dist[t] + w){
                dist[v] = dist[t] + w;
            }
        }
    }
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &w);
        edges[a].emplace_back(w, b);
    }
    dijstra(s);
    for (int i = 1; i <= n; i++){
        if(dist[i] != 0x3f3f3f3f){
            printf("%d ", dist[i]);
        }else{
            printf("%d ", INT_MAX);
        }
    }
    printf("\n");
    return 0;
}