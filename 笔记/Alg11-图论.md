### 📘本章纲要

使用STL提供的容器即可完成对图结构优雅的存储。如果希望效率更快，可以使用数组模拟邻接表，也即使用链式前向星存图即可，同样的套路也适用于树结构。

- 如何建图并遍历图结构
  
  - 图结构的存储方式
  
    - 连边表 (Edges List, 通常使用 `vector<iii>` 实现)
  
    - 邻接表 (Adjacency List, 通常使用 `vector<vii>` 实现)
  
    - 邻接矩阵 (Adjacency Matrix, 通常使用 `AM[N][N]` 实现)
  
  - 图结构的遍历方式
  
    - 深度优先搜索
    - 宽度优先搜索
- 关键路径与拓扑排序
- 生成树问题 (※)
- 最短路问题 (※)
- 连通性问题 (※)
  - Gabow 强连通分量算法
  - Tarjan 强连通分量算法
    - Tarjan 缩点，vDCC缩点
    - Tarjan 割点，eDCC缩点 
    - Tarjan 割边

- 小规模二分图匹配
  - 宽搜染色法判定可否构成二分图
  - HA算法 (匈牙利算法)
  - KM算法 (匈牙利算法变体)
  
- 网络流建模





### 📘网络流建模

网络流用途非常广泛，通过对实际问题建模套用网络流模型的解决问题的案例非常多，完全能够单独构成一个章节细说网络流的作用。

- 网络流引入 (观看蒋炎岩老师[讲解](https://www.bilibili.com/video/BV1Q7411R7ie/?spm_id_from=333.788.recommend_more_video.18&vd_source=28f330d27174f33e35b3e0c9c5c64407)视频)
- 网络流问题
  - Ford-Fulkerson 算法
  - HLPP (Highest-Label-Preflow-Push) 算法
  - **Edmonds-Karp 算法**
    - 最值费用流：替换BFS改成SPFA即可解决最大或最小费用流问题
  - **Dinic & ISAP (Improved Shortest Augument Path)**
    - 最少割点：通过拆点为边的方式转为割点为最小割边问题
    - 最小路径覆盖
- 大规模二分图匹配
- 上下界可行流
- 关键边
- **图论对偶定理汇总**
  - *Dilworth*：任意偏序集的最长链与最短链个数等于其各自反链的长度！
  -  *König*：二分图中的最大匹配数等于这个图中的最小点覆盖数！
  - *MaxFlowMinCut*：最大流的流量等于最小割的容量！



### 🦉二分图匹配模板

#### 匈牙利算法-DFS

```c++
int n1, n2, m, a, b;
int find(int u){
    for (int v : edges[u]) {
        if (vist[v]) {
            if (!match[v] || dfs(mamth[v])){
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}
```

#### 匈牙利算法-BFS

```c++
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
```

#### KM算法-DFS

```c++

```



#### KM算法-BFS

```c++
void aug(int x) {
    while(x){
        int t = ps[prec[x]];
        ps[prec[x]] = x;
        pt[x] = prec[x];
        x = t;
    }
}

void bfs(int x){
    fill(slack + 1, slack + n2 + 1, 2e9);
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
```





### 🦉网络流算法模板

#### Res-Graph-Built

```c++
typedef long long ill;
typedef unsigned long long ull;

// 残留网络建图，此处一个非常重要的细节便是 idx = 1 而非 0，这是为了方便更新残留网络的反向边
int head[MAXN], vex[MAXN], wgt[MAXN], nxt[MAXN], idx = 1;
void add_edge(int x, int y, int w) {
    vex[++idx] = y, wgt[idx] = w, nxt[idx] = head[x], head[x] = idx;
}

...
  
int build_graph() {
    scanf("%d %d %d %d", &n, &m, &src, &dst);
    for (int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        add_edge(a, b, c);
        add_edge(b, a, 0);
    }
		...
    return 0;
}
```



#### Ford-Fulkerson

```c++
// Ford-Fulkerson会走很多弯路，基本通过不了任何数据较强的题目
int n, m, a, b, c;
int vis[MAXN], prec[MAXN], src, dst;

int dfs(int u, int flow = 2e9){
    if(u == dst){
        return flow;
    }
    vis[u] = 1;
    for (int i = head[u]; i; i = nxt[i]){
        int v = vex[i], ret;
        if (wgt[i] && !vis[v] && (ret = dfs(v, min(flow, wgt[i]))) != -1) {
            wgt[i] -= ret;
            wgt[i ^ 1] += ret;
            return ret;
        }
    }
    return -1;
}

inline llong ford_fulkerson(){
    llong ret, flow = 0;
    while ((ret = dfs(src)) != -1) {
        memset(vis, 0, sizeof(vis));
        flow += ret;
    }
    return flow;
}
```



#### Edmonds-Karp

```c++
/**
 * EK 算法是对 FF 算法的一个优化, 使用宽搜代替深搜，通过类似于深度(或说最短路)这种方式对模型分层，
 * 其中 mf[v] 存储源点到达顶点 v 所允许的最大流量，思想上面很像 Dijkstra 最短路，也像 Prim 最小生成树，
 */ 
int n, m, a, b, c;
int mf[MAXN], prec[MAXN], src, dst;

bool bfs(){
    memset(mf, 0, sizeof(mf));
    mf[src] = 2e9;
  
    queue<int> q;
    q.push(src);

    while(q.size()){
        int u  = q.front(); q.pop();
        for (int i = head[u]; i; i = nxt[i]){
            llong v = vex[i], w = wgt[i];
            if(mf[v] == 0 && w > 0){
                mf[v] = min(mf[u], wgt[i]);
                prec[v] = i;
                q.push(v);
            }
        }
    }
    return mf[dst] != 0;
}

llong edmonds_karp(){
    llong ans = 0;
    while(bfs()){
      	// 从汇点沿着反向边出发逐渐更新源点，正向边减少，反向边增加 (残留网络提供的反悔机制)
        for (int v = dst, i = prec[v]; v != src; v = vex[i ^ 1], i = prec[v]) {
            wgt[i] -= mf[dst];
            wgt[i ^ 1] += mf[dst];
        }
        ans += mf[dst];
    }
    return ans;
}
```



#### Improved-Dinic

```c++
/**
 *  其实idx 初始化等于 0 亦可，只要 head 初始化-1，然后判断空节点的时候使用 ~i 即可
 *  由于图中可能有环，遇环有可能会耗费大量时间乃至死循环，为此需要分层处理，下面是几种常用的优化，
 *     1. 通过分层限制搜索深度，优化搜索顺序
 *     2. 通过当前弧剪枝排除已被榨干流量的路径
 *     3. 通过剩余流量剪枝，约束源点与汇点之外的顶点流入等于流出
 *     4. 通过残枝优化剪枝，把那些不可能走到汇点的节点全部剔除
 *  如果添加一个断层优化，并把分层过程反过来，先从汇点出发，那么 Dinic 算法也就变成了 ISAP 算法了！
*/ 

int n, m, a, b, c;
int dep[MAXN], curr[MAXN], src, dst;

bool bfs(){
    memcpy(curr, head, sizeof(head));
	  memset(dep, 0, sizeof(dep));
    dep[src] = 1;
 
  	queue<int> q;
    q.push(src);
 
    while(q.size()){
        int u  = q.front(); q.pop();
        for(int i = head[u]; i; i = nxt[i]) {
            llong v = vex[i], w = wgt[i];
            if (dep[v] == 0 && w > 0) {
                dep[v] = dep[u] + 1;
                q.push(v);
            }
        }
    }
    return dep[dst] != 0;
}

int dfs(int u, int iflow = 2e9){
    if(u == dst){
        return iflow;
    }
    int oflow = 0;
    for (int i = curr[u]; i && iflow; i = nxt[i]) {
        curr[u] = i;
        int v = vex[i], w = wgt[i];
        if(dep[v] == dep[u] + 1 && w > 0){
            int ret = dfs(v, min(iflow, w));
            wgt[i] -= ret, iflow -= ret;
            wgt[i ^ 1] += ret, oflow += ret;
        }
    }
    return oflow ? oflow : (dep[u] = 0);//残枝优化
}

int Dinic(){
    int ans = 0;
    while(bfs()){
        ans += dfs(src);
    }
    return ans;
}
```



#### Improved-SAP

```c++
// Improved Shortest Augument Path
int n, m, a, b, c;
int dep[MAXN], gap[MAXN], curr[MAXN], src, dst;

// 如果 dep 初始化-1，那么退出条件可以设为 n，然后 isap 退出等于 n 时候退出循环
void bfs(){
    memset(dep, 0, sizeof(dep));
    memset(gap, 0, sizeof(gap));
    dep[dst] = 1, gap[1] = 1;

    queue<int> q;
    q.push(dst);

    // 此处务必注意，这里是对残留网络反向计算深度dep！
    while(q.size()){
        int u = q.front();q.pop();
        for(int i = head[u]; i; i = nxt[i]) {
            int v = vex[i], w = wgt[i];
            if (dep[v] == 0 && w == 0) {
                dep[v] = dep[u] + 1;
                ++gap[dep[v]];
                q.push(v);
            }
        }
    }
}

int dfs(int u, int iflow = 2e9){
    if(u == dst){
        return iflow;
    }
  
		int used = 0;
    for (int i = curr[u]; i && iflow; i = nxt[i]){
        curr[u] = i;
        llong v = vex[i], w = wgt[i];
        if (dep[v] + 1 == dep[u] && w > 0) {
            int ret = dfs(v, min(iflow - used, w));
            used += ret;
            wgt[i] -= ret;
            wgt[i ^ 1] += ret;
            if(used == iflow){
                return iflow;
            }
        }
    }
  
    // 此处也是一个 trick，正常写法应为HLPP那样，需要遍历多个顶点寻找最高顶点 t，然后使其恰好高于 t
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
```



#### HL-Preflow-Push

```c++
/**
 *  截止 2022，目前理论效率最高的最大流算法，Highest-Label-Preflow-Push，虽然算法常数较大，
 *  其它算法基于增广路实现，但是HLPP非也，HLPP 是基于预留进行实现的，其打破了平衡条件(流入等于流出)限制，
 *  这种算法是将每个节点当做自高向低流动的蓄水池，然后自高向低流动，直到流不动再调整各个顶点的高度继续流动！
*/ 
int n, m, a, b, c;
int dep[MAXN], gap[MAXN], exce[MAXN], curr[MAXN], inq[MAXN], src, dst;

// 重载优先队列的比较需要传入一个类别，一个简便的方式是传入一个结构体然后重载()运算符
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
 * 顶点 u 自高相抵推送自己的流量予周围相邻的节点，且推送的流量不可以超过连边的限制
 * 如果 u 存储的流量已经耗尽则提前退出推送
 */ 
void push_flow(int u){
    for (int i = head[u]; i && exce[u]; i = nxt[i]){
        int v = vex[i], w = wgt[i];
        if(dep[v] + 1 == dep[u] && w > 0){
            int mf = min(exce[u], w);
            wgt[i] -= mf, exce[u] -= mf
            wgt[i ^ 1] += mf, exce[v] += mf;
            if (v != src && v != dst && !inq[v]){
                heap.push(v);
                inq[v] = 1;
            }
        }
    }
}

/**
 *  如果周围节点都高于u，但是 u 又有存有超额流，那么修改 u 高度，此处设为INF是一个小技巧
 *  使其能恰好能够高于相邻顶点中最高顶点一个单位高度即可，
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

/**
 * 主干的 hlpp 过程类似于 push 只有条件判断的地方不同，src 源点无脑推流即可，无需按层进行推流，
 * 源点推流之后，会把自己的流量分到周围的顶点，这些顶点统统入队，然后按照自高向低的优先顺序进行推流即可，
 */ 
int hlpp(int u = src){
    if(!bfs()){
        return 0;
    }
    dep[u] = n;
    for (int i = head[u]; i; i = nxt[i]){
        int v = vex[i], w = wgt[i];
        if(w > 0){
            wgt[i] -= w, exce[u] -= w;
            wgt[i ^ 1] += w, exce[v] += w;
            if (v != src && v != dst && !inq[v]){
                heap.push(v);
                inq[v] = 1;
            }
        }
    }
    // 推送结束之后若仍存在超额流, 抬高t, 如果顶点 t 出现断层, 高于 t 那些顶点也不再可能往下流动, 全部抬高
    while(heap.size()){
        int t = heap.top(); heap.pop(); inq[t] = 0;
        push_flow(t); 
        if(exce[t]){
            if (--gap[dep[t]] == 0) {
                for (int v = 1; v <= n; v++){
                    if (v != src && v != dst && dep[v] > dep[t] && dep[v] < n + 1) {
                        dep[v] = n + 1;
                    }
                }
            }
            relabel(t);
            ++gap[dep[t]];
            heap.push(t); inq[t] = 1;
        }
    }
    return exce[dst];
}
```





### ⚔️网络流模型的广泛应用

|        题目        |                           思路描述                           |
| :----------------: | :----------------------------------------------------------: |
| LG1344. 追查坏牛奶 | 两次建图跑最大流，或者建图 w=wx+1，再对 x下取整得最小割，取余数得边数 |
| LG1345. 奶牛的电信 |               拆点成边，转换割点问题为割边问题               |
| LG2057. 善意的投票 | 相当于分成两个集合，设置源点、汇点分别连接不同的立场的小孩，再求最小割 |

