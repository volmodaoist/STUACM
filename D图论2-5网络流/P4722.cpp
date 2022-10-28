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
#define  MAXN  300005


int head[MAXN], vex[MAXN], wgt[MAXN], nxt[MAXN], idx = 1;
int dep[MAXN], gap[MAXN], exce[MAXN], curr[MAXN], inq[MAXN], src, dst;
int n, m, a, b, c;

void add_edge(int x, int y, int w) {
    vex[++idx] = y, wgt[idx] = w, nxt[idx] = head[x], head[x] = idx;
}

// �������ȶ��еıȽ���Ҫ����һ�����һ�����ķ�ʽ�Ǵ���һ���ṹ��Ȼ������()�����
struct cmp{
    bool operator()(int a, int b) const{
        return dep[a] < dep[b];
    }
};
priority_queue<int, vector<int>, cmp> heap;


bool bfs(){
    memset(dep, 0x3f, sizeof(dep));
    memset(gap, 0, sizeof(gap));
    dep[dst] = 1, gap[1] = 0;

    queue<int> q;
    q.push(dst);

    while(q.size()){
        int u = q.front();q.pop();
        for(int i = head[u]; i; i = nxt[i]) {
            int v = vex[i], w = wgt[i];
            if (dep[v] > dep[u] + 1 && w == 0) {
                dep[v] = dep[u] + 1;
                ++gap[dep[v]];
                q.push(v);
            }
        }
    }
    return dep[src] != 0;
}

/**
 * ���� u �Ը���������Լ�����������Χ���ڵĽڵ㣬�����͵����������Գ������ߵ�����
 * ��� u �洢�������Ѿ��ľ�����ǰ�˳�����
 */ 
void push(int u){
    for (int i = head[u]; i && exce[u]; i = nxt[i]){
        int v = vex[i], w = wgt[i];
        if(dep[v] + 1 == dep[u] && w > 0){
            int mf = min(exce[u], w);
            wgt[i] -= mf;
            wgt[i ^ 1] += mf;
            exce[u] -= mf;
            exce[v] += mf;
            if (v != src && v != dst && !inq[v]){
                heap.push(v);
                inq[v] = 1;
            }
        }
    }
}

/**
 *  �����Χ�ڵ㶼����u������ u ���д��г���������ô�޸� u �߶ȣ��˴���ΪINF��һ��С����
 *  ʹ����ǡ���ܹ��������ڶ�������߶���һ����λ�߶ȼ��ɣ�
 */ 
void relabel(int u){
    dep[u] = INF;
    for (int i = head[u]; i; i = nxt[i]){
        int v = vex[i], w = wgt[i];
        if(dep[v] + 1 < dep[u] && w > 0){
            dep[u] = dep[v] + 1;
        }
    }
}

int hlpp(int u = src){
    if(!bfs()){
        return 0;
    }
    // ���ɹ��������� push ֻ�������жϵĵط���ͬ��src Դ�������������ɣ����谴���������
    dep[u] = n;
    for (int i = head[u]; i; i = nxt[i]){
        int v = vex[i], w = wgt[i];
        if(w > 0){
            wgt[i] -= w;
            wgt[i ^ 1] += w;
            exce[u] -= w;
            exce[v] += w;
            if (v != src && v != dst && !inq[v]){
                heap.push(v);
                inq[v] = 1;
            }
        }
    }
    while(heap.size()){
        int t = heap.top(); heap.pop();
        inq[t] = 0;
        push(t);
        // ���ͽ���֮����Ȼ���ڳ������������� t ̧��
        if(exce[t]){
            if (--gap[dep[t]] == 0) {
                // ������� t ���ֶϲ㣬���и��ڶ��� t ��Щ������ȻҲ���ٿ���������������ʱ������Ϊ����̧��
                for (int v = 1; v <= n; v++){
                    if (v != src && v != dst && dep[v] > dep[t] && dep[v] < n + 1) {
                        dep[v] = n + 1;
                    }
                }
            }
            relabel(t);
            ++gap[dep[t]];
            heap.push(t);
            inq[t] = 1;
        }
    }
    return exce[dst];
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
    printf("%d\n", hlpp());
    return 0;
}