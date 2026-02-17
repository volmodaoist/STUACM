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


typedef long long ill;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
#define  MAXN  100005

int n1, n2, m, a, b;
int ps[MAXN], pt[MAXN], prec[MAXN], vist[MAXN];
vector<int> edges[MAXN];

void aug(int x){
    while(x){
        int t = ps[prec[x]];
        ps[prec[x]] = x;
        pt[x] = prec[x];
        x = t;
    }
}
bool bfs(int x){
    memset(vist, 0, sizeof(vist));
    memset(prec, 0, sizeof(prec));
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v: edges[u]){
            if(!vist[v]){
                vist[v] = 1;
                prec[v] = u;
                if(!pt[v]){
                    aug(v);
                    return true;
                }else{
                    q.push(pt[v]);
                }
            }
        }
    }
    return false;
}




int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif    

    scanf("%d %d %d", &n1, &n2, &m);
    for (int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
    }

    int ans = 0;
    for (int i = 1; i <= n1; i++) {
        if(bfs(i)){
            ans++;
        }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n1; i++){
        printf("%d ", ps[i]);
    }
    printf("\n");
    return 0;
}