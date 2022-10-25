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
- 网络流建模





### 📘网络流建模

网络流用途非常广泛，通过对实际问题建模套用网络流模型的解决问题的案例非常多，完全能够单独构成一个章节细说网络流的作用。

- 网络流引入 (观看蒋炎岩老师[讲解](https://www.bilibili.com/video/BV1Q7411R7ie/?spm_id_from=333.788.recommend_more_video.18&vd_source=28f330d27174f33e35b3e0c9c5c64407)视频)

- 网络流问题 (※)
  - 基于增广路的网络流算法
    - Ford-Fulkerson 算法
    - Edmonds-Karp 算法
    - Dinic & ISAP (相当于多路增广DFS，也是最常用的算法)
      - 通过的分层限制搜索的深度，进行搜索顺序优化
      - 通过当前弧剪枝，排除已被榨干流量的路径
      - 通过剩余流量剪枝，约束源点与汇点之外的顶点流入等于流出
      - 通过残枝优化剪枝，把那些不可能走到汇点的节点全部剔除
  
  - 基于预留推进的最大流算法 ***HLPP 最高标记预流推进算法***
  
- 大规模二分图匹配
- 上下界可行流
- 关键边
- 拆点
- **图论对偶定理汇总**
  - *Dilworth*：任意偏序集的最长链与最短链个数等于其各自反链的长度！
  -  *König*：二分图中的最大匹配数等于这个图中的最小点覆盖数！
  - *MaxFlowMinCut*：最大流等于最小割！





### 🦉网络流算法模板

#### Residual Graph Built

```c++
typedef long long llong;
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
            int v = vex[i];
            if(mf[v] == 0 && wgt[i]){
                mf[v] = min(mf[u], wgt[i]);
                prec[v] = i;
                q.push(v);
                if(v == dst) return true;
            }
        }
    }
    return false;
}

llong edmonds_karp(){
    llong flow = 0;
    while(bfs()){
      	// 从汇点沿着反向边出发逐渐更新源点，正向边减少，反向边增加 (残留网络提供的反悔机制)
        for (int v = dst, i = prec[v]; v != src; v = vex[i ^ 1], i = prec[v]) {
            wgt[i] -= mf[dst];
            wgt[i ^ 1] += mf[dst];
        }
        flow += mf[dst];
    }
    return flow;
}
```



#### Improved-Dinic

```c++
/**
 *  其实idx 初始化等于 0 亦可，只要 head 初始化-1，然后判断空节点的时候使用 ~i 即可
 *  由于图中可能存在环，一旦遇到环有可能会耗费大量时间，甚至进入死循环，为此要将图分层处理，
*/ 

int n, m, a, b, c;
int dep[MAXN], curr[MAXN], src, dst;

bool bfs(){
    memset(dep, 0, sizeof(dep));
    memcpy(curr, head, sizeof(head));
    dep[src] = 1;
  
  	queue<int> q;
    q.push(src);
  
  	// 也有一些同学会把 dep 初始化无穷大，然后函数返回时判断 dep[dst]是否已被更新
    while(q.size()){
        int u  = q.front();q.pop();
        for(int i = head[u]; i; i = nxt[i]) {
            int v = vex[i], w = wgt[i];
            if (dep[v] == 0 && w > 0) {
                dep[v] = dep[u] + 1;
                q.push(v);
                if (v == dst){
                  	return true;
                }
            }
        }
    }
    return false;
}

// Dinic dfs 写法有多种，一种是维护iflow与oflow相等的写法，一种使用used 维护已经使用的流量
llong dfs(int u, int iflow = 2e9){
    if(u == dst){
        return iflow;
    }
    llong used = 0;
    for (int i = curr[u]; i && iflow; i = nxt[i]) {
        curr[u] = i;
        int v = vex[i], w = wgt[i];
        if (dep[v] == dep[u] + 1 && w > 0) {
            // 最常见的模板是把函数的 iflow 参数当做常量，然后递归 dfs 传参的时候写成相减形式
            llong ret = dfs(v, min(iflow - used, 0LL + w));
            wgt[i] -= ret;
            wgt[i ^ 1] += ret;
            used += ret;
            if(used == iflow){
                return iflow;
            }
        }
    }
    return used;
}

llong Dinic(){
    llong flow = 0;
    while(bfs()){
        flow += dfs(src);
    }
    return flow;
}
```



#### Improved-SAP

```c++
// Improved Shortest Augument Path
int n, m, a, b, c;
int dep[MAXN], gap[MAXN], curr[MAXN], src, dst;

// 如果dep 初始化-1，那么退出条件可以设为 n，然后 isap 退出等于 n 时候退出循环
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
 *  上述算法基于增广路思想，但是 HLPP 打破了平衡条件(流入等于流出)，其将每个节点当做自高向低流动的蓄水池，
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
    // 推送结束之后若仍存在超额流, 抬高t, 如果顶点 t 出现断层, 高于 t 那些顶点也不再可能往下流动, 全部抬高
    while(heap.size()){
        int t = heap.top(); heap.pop();
        inq[t] = 0;
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
            heap.push(t);
            inq[t] = 1;
        }
    }
    return exce[dst];
}
```









### ⚔️网络流模型的广泛应用
