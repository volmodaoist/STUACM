
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


// �����������С��
// �Ƽ��Ķ���ƪ֪������ https://www.zhihu.com/question/29868843/answer/122858292
typedef long long llong;
typedef unsigned long long ull;
#define  MAXN  300005

// �˴�һ��ϸ�ڱ��� idx = 1 ���� 0
int head[MAXN], vex[MAXN], wgt[MAXN], nxt[MAXN], idx = 1;
int dep[MAXN], gap[MAXN], curr[MAXN], src, dst;
int n, m, a, b, c;

// mf[v] �洢Դ�㵽�ﶥ�� v ��������������
void add_edge(int x, int y, int w) {
    vex[++idx] = y, wgt[idx] = w, nxt[idx] = head[x], head[x] = idx;
}

//��ȳ�ʼ��-1 Ҳ�ǿ��Ե�
void bfs(){
    memset(dep, 0, sizeof(dep));
    memset(gap, 0, sizeof(gap));
    dep[dst] = 1, gap[1] = 1;

    queue<int> q;
    q.push(dst);

    while(q.size()){
        int u = q.front();q.pop();
        for(int i = head[u]; i; i = nxt[i]) {
            int v = vex[i], w = wgt[i];
            if (dep[v] == -1 && w == 0) {
                dep[v] = dep[u] + 1;
                ++gap[dep[v]];
                q.push(v);
            }
        }
    }
}


llong dfs(int u, int iflow = 2e9){
    if(u == dst){
        return iflow;
    }
    llong used = 0;
    for (int i = curr[u]; i && iflow; i = nxt[i]){
        curr[u] = i;
        llong v = vex[i], w = wgt[i];
        if (dep[v] + 1 == dep[u] && w > 0) {
            llong ret = dfs(v, min(iflow - used, w));
            used += ret;
            wgt[i] -= ret;
            wgt[i ^ 1] += ret;
            if(used == iflow){
                return iflow;
            }
        }
    }
    
    // ���dep ��ʼ��-1����ô�˳�����������Ϊ n��Ȼ�� isap �˳����� n ʱ���˳�ѭ��
    if(--gap[dep[u]] == 0){
        dep[src] = n + 1;
    }
    ++dep[u];
    ++gap[dep[u]];
    return used;
}

llong isap(){
    bfs();
    llong flow = 0;
    while (dep[src] <= n) {
        memcpy(curr, head, sizeof(head));
        flow += dfs(src);
    }
    return flow;
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d %d %d %d", &n, &m, &src, &dst);
    for (int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        add_edge(a, b, c);
        add_edge(b, a, 0);
    }
    printf("%lld\n", isap());
    return 0;
}