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
            // 取出候选队列(可能是要寻找对象，或者是要更换对象的顶点)然后将其纳入交错路径之中
            int u = q.front(); q.pop();
            vs[u] = 1; 
            for (int v = 1; v <= n2; v++){
                if(!vt[v]){ // 枚举右部不在交错树中的顶点(黄色部分)
                    if(ls[u] + lt[v] - e[u][v] < slack[v]){ // 寻找降低标准的最低限度
                        slack[v] = ls[u] + lt[v] - e[u][v];
                        prec[v] = u;
                    } // 同时更新前驱顶点
                    if(!slack[v]){  // 如果需要降低标准限度为零说明恰好找到了能够加入相等子图的连边
                        vt[v] = 1;  // 先将这个顶点加入交错路径之中(放入右侧红色部分)
                        if(!pt[v]){ // 如果这个顶点尚未匹配，为其寻找一个可行的匹配方案(寻找一条增广路径)
                            aug(v);
                            return;
                        } else {
                            q.push(pt[v]); // 否则将其已匹配的对象放入等待更换对象的候选队列
                        }
                    }
                }
            }
        }
        // 增广失败的时候扩大子图(大家的标准都太高了，实在找不到任何合适的对象，也即找不到增广路径)
        int delta = 2e9;
        for (int v = 1; v <= n2; v++) {
            if(!vt[v]){ // 扫描slack, 根据右侧集合黄色部分顶点需要降低最低限度再挑一个最小的
                delta = min(delta, slack[v]); // 矮子里面再挑矮个子
            }
        }
        if(delta == 2e9) break;
        for (int i = 1; i <= n1; i++) if(vs[i]) ls[i] -= delta;
        for (int i = 1; i <= n2; i++) if(vt[i]) lt[i] += delta; else slack[i] -= delta;

        // 然后再看降低标准之后，右侧集合不在交错路径中的那些顶点是否有符合标准的顶点
        for (int v = 1; v <= n2; v++) {
            if (!vt[v] && !slack[v]){
                vt[v] = 1;
                if(!pt[v]){ // 若是找到符合等式约束且未匹配的，为其找增广路
                    aug(v);
                    return;
                }else{
                    q.push(pt[v]); // 否则进队，这个部分逻辑与上面是一样的
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

    // 左部的顶点个数、右部的顶点个数、连边的个数
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
    for (int i = 1; i <= n2; i++){
        if(e[i][ps[i]]){
            printf("%d ", ps[i]);
        }else{
            printf("0 ");
        }
    }
    printf("\n");
    return 0;
}