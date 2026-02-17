#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))

#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
#define  MAXN  505

int a, b, c, n, m;
ill slack[MAXN], ls[MAXN], lt[MAXN];
ill g[MAXN][MAXN], match[MAXN], prec[MAXN], vt[MAXN];

// 虚设一个顶点 q，使其与当前顶点 u 匹配, 此处 match 记录右侧顶点匹配的左侧顶点
void bfs(int u){
    ill p = 0, q = 0, idx = 0, delta = 0;
    memset(prec, 0, sizeof(prec));
    memset(slack, 0x7f, sizeof(slack));
    match[q] = u;
    do{
        p = match[q], vt[q] = 1, delta = 1e18;
        for (int i = 1; i <= n; i++) {
            if(vt[i]) continue;
            if(slack[i] > ls[p] + lt[i] - g[p][i]){
                slack[i] = ls[p] + lt[i] - g[p][i];
                prec[i] = q;
            }
            // 使用顶标与连边的差值维护松弛量slack使其尽可能小，然后从中找出最小的松弛量及其下标
            if(slack[i] < delta){
                delta = slack[i];
                idx = i;
            }
        }
        // 我们只在乎右侧顶点集合是否处于交错树中
        for (int i = 0; i <= n; i++){
            if(vt[i]){
                ls[match[i]] -= delta, lt[i] += delta;
            } else {
                slack[i] -= delta;
            }
        }
        q = idx; // 使用最小 slack 顶点来更新右侧顶点
    } while (match[q]); // 当前最小 slack 如果连着虚设顶点说明已经无路可走了
    while(q) match[q] = match[prec[q]], q = prec[q]; // 沿着交错路重新更新匹配关系
}


ill KM(){
    memset(match, 0, sizeof(match));
    memset(ls, 0, sizeof(ls));
    memset(lt, 0, sizeof(lt));
    for (int i = 1; i <= n; i++){
        memset(vt, 0, sizeof(vt));
        bfs(i);
    }
    ill ans = 0;
    for (int i = 1; i <= n; i++){
        if(match[i]){
            ans += g[match[i]][i];
        }
    }
    return ans;
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d %d", &n, &m);
    memset(g, 0x80, sizeof(g));
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        g[a][b] = max(g[a][b], 0LL + c);
    }
    printf("%lld\n", KM());
    for (int i = 1; i <= n; i++){
        printf("%d ", match[i]);
    }
    printf("\n");
    return 0;
}