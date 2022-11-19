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
#define  MAXN  155
#define	 INF   1e18

typedef struct _Node{
    int x, y;
} Node;

double dist(Node& a, Node& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}


int n, x, y;
Node nodes[MAXN];

int adj[MAXN][MAXN], farm[MAXN];
double g[MAXN][MAXN], diameter[MAXN], max_sp[MAXN];

void dfs(int i, int id){
    farm[i] = id;
    for (int j = 0; j < n; j++){
        if(!farm[j] && g[i][j] < INF){
            dfs(j, id);
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
        scanf("%d %d", &x, &y);
        nodes[i] = {x, y};
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%1d", &adj[i][j]);
            if(adj[i][j] || i ==j ){
                g[i][j] = dist(nodes[i], nodes[j]);
            }else{
                g[i][j] = INF;
            }
        }
    }
    int id = 0;
    for (int i = 0; i < n; i++){
        if(!farm[i]){
            dfs(i, ++id);
        }
    }

    for (int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(g[i][j] > g[i][k] + g[k][j]){
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }


    // 算出每个农场的最大最短路
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(g[i][j] < INF){
                max_sp[i] = max(max_sp[i], g[i][j]);
            }
        }
        diameter[farm[i]] = max(diameter[farm[i]], max_sp[i]);
    }

    double max_d = 0, min_d = INT_MAX;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(farm[i] != farm[j]){
                max_d = max(
                    max(diameter[farm[i]], diameter[farm[j]]),
                    dist(nodes[i], nodes[j])  + max_sp[i] + max_sp[j]
                );
                min_d = min(min_d, max_d);
            }
        }
    }
    printf("%.6f\n", min_d);
    return 0;
}