#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define  MAXN  100005

int n, x[MAXN], vis[MAXN], path[MAXN];

void dfs(int plen){
    if(plen == n){
        for (int i = 0; i < plen; i++) {
            printf("%5d", path[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < n; i++){
        if(!vis[i]){
            vis[i] = 1;
            path[plen] = x[i];
            dfs(plen + 1);
            vis[i] = 0;
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
        x[i] = i + 1;
    }
    dfs(0);

    return 0;
}