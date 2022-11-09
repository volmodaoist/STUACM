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
#define  MAXN  1000

int n1, n2, m, a, b, c;
int ps[MAXN], pt[MAXN], vs[MAXN], vt[MAXN], prec[MAXN], slack[MAXN];
int e[MAXN][MAXN], ls[MAXN], lt[MAXN];

void aug(int x) {
    while(x){
        int t = ps[prec[x]];
        ps[prec[x]] = x;
        pt[x] = prec[x];
        x = t;
    }
}

void bfs(int x){
    fill(slack + 1, slack + n2 + 1, 0x3f3f3f3f);
    memset(prec, 0, sizeof(prec));
    memset(vs, 0, sizeof(vs));
    memset(vt, 0, sizeof(vt));

    queue<int> q;
    q.push(x);
    while(1){
        while(q.size()){
            int u = q.front(); q.pop();
            vs[u] = 1;
            for (int v = 1; v <= n2; v++){
                if(!vt[v]){
                    if(ls[u] + lt[v] - e[u][v] < slack[v]){
                        slack[v] = ls[u] + lt[v] - e[u][v];
                        prec[v] = u;
                    }
                    if(!slack[v]){
                        vt[v] = 1;
                        if(!pt[v]){
                            aug(v);
                            return;
                        } else {
                            q.push(pt[v]);
                        }
                    }
                }
            }
        }
        // 增广失败的时候扩大子图
        int delta = 2e9;
        for (int v = 1; v <= n2; v++) {
            if(!vt[v]){
                delta = min(delta, slack[v]);
            }
        }
        if(delta == 2e9) break;
        for (int i = 1; i <= n1; i++) if(vs[i]) ls[i] -= delta;
        for (int i = 1; i <= n2; i++) if(vt[i]) lt[i] += delta; else slack[i] -= delta;

        for (int v = 1; v <= n2; v++) {
            if (!vt[v] && !slack[v]){
                vt[v] = 1;
                if(!pt[v]){
                    aug(v);
                    return;
                }else{
                    q.push(pt[v]);
                }
            }
        }
    }
}



int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif    

    scanf("%d %d %d", &n1, &n2, &m);
    n2 = max(n1, n2);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        e[a][b] = c;
    }

    for (int i = 1; i <= n1; i++){
        for (int j = 1; j <= n2; j++){
            ls[i] = max(ls[i], e[i][j]);
        }
    }
    for (int i = 0; i <= n1; i++){
        bfs(i);
    }
    ill ans = 0;
    for (int i = 1; i <= n1; i++) ans += ls[i];
    for (int j = 1; j <= n2; j++) ans += lt[j];
    printf("%lld\n", ans);
    for (int i = 1; i <= n1; i++){
        if(e[i][ps[i]]){
            printf("%d ", ps[i]);
        }else{
            printf("0 ");
        }
    }
    printf("\n");
    return 0;
}