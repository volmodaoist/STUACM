#include<bits/stdc++.h>
using namespace std;

typedef long long ill;
#define MAXN 100005

int n, m, a, b, c, src, dst;
int head[MAXN], vex[MAXN], wgt[MAXN], nxt[MAXN], idx = 1;
int prec[MAXN], mf[MAXN];
void add_edge(int x, int y, int w){
    vex[++idx] = y, wgt[idx] = w, nxt[idx] = head[x], head[x] = idx;
}

bool bfs(){
    memset(mf, 0, sizeof(mf));
    mf[src] = 2e9;
    
    queue<int> q;
    q.push(src);
    while(q.size()){
        int u = q.front(); q.pop();
        for(int i = head[u]; i; i = nxt[i]){
            int v = vex[i], w = wgt[i];
            if(mf[v] == 0 && w > 0){
                mf[v] = min(mf[u], w);
                prec[v] = i;
                q.push(v);
                if(v == dst) return true;
            }
        }
    }
    return false;
}

ill EK(){
    ill ans = 0;
    while(bfs()){
        for(int v = dst, i = prec[v]; v != src; v = vex[i ^ 1], i = prec[v]){
            wgt[i] -= mf[dst];
            wgt[i ^ 1] += mf[dst];
        }
        ans += mf[dst];
    }
    return ans;
}


int main(){
    scanf("%d %d %d %d", &n, &m, &src, &dst);
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        add_edge(a, b, c);
        add_edge(b, a, 0);
    }
    printf("%lld\n", EK());
    return 0;
}