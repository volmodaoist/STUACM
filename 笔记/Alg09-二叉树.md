### 🎄本章纲要

- 二叉树具有何种性质
  - 如何建立一棵二叉树
  - 如何遍历一棵二叉树 (前序、中序、后序）
  - 二叉树的基本属性计算
    - 树直径
    - 树中心
    - 树重心
- 无根树建立
- 树链剖分 (※ 重中之重)
  - 轻重或长短剖分
  - 访问次数剖分
- 树上信息维护(树链剖分+线段树/平衡树)
  - 最近公共祖先
    - 树上倍增
    - 树链剖分
    - TarjanLCA





### 🪵树链剖分

树链剖分主要采用轻重链剖分，完成剖分之后：

(1) 树会被分成若干重链; 

(2) 轻儿子必然是每条重链的顶点；

(3) 任意一条路径会被分成重链，数量不多于 $O(\log N)$；

算法流程方面需要两次 dfs 获取不同的信息，一次建树获取基本信息，一次分解获取重链轻链。经过这种转化得到的一条重链，其上每个节点的编号是整形连续的，此时能用线段树维护树上信息。







### 🌱最近公共祖先







### 🐉基环树

严格来说，基环树并非树结构，而是图结构。基环树是在树上面添加一个环，仅有一个环形结构的图结构称为基环树。基环树可以视为以环点为根的若干子树构成。基环树一般不单独出现，会结合树形dp考察，其主要解法是拆边成林，并对基环树森林进行树形dp。







### 🦉本文提到的算法模板

#### 两次深搜树链剖分

```C++
vector<int> edges[MAXN];
int ft[MAXN], dep[MAXN], siz[MAXN], hev[MAXN];
int wt[MAXN], top[MAXN], id[MAXN], nw[MAXN], idx;

// 第一次递归获取父节点、深度、子树大小等信息用于下一次剖分
void tree_build(int u, int father) {
    ft[u] = father, dep[u] = dep[father] + 1, siz[u] = 1;
    for (auto v : edges[u]) {
        if(v == father)
            continue;
        tree_build(v, u);
        siz[u] += siz[v];
        if(siz[hev[u]] < siz[v]) hev[u] = v;
    }
}

// 第二次递归更新的链头，并按顺序对树序列化，先走重节点，其余每个轻节点都单独构成一条链，且链头便是其本身
void tree_decomposition(int u, int t){
    top[u] = t, id[u] = ++cnt, nw[cnt] = wt[u];
    if(!hev[u]) return;
    tree_decomposition(hev[u], t);
    for(int v: edges[u]){
        if (v == ft[u] || v == hev[u])
            continue;
        tree_decomposition(v, v);
    }
}

/** 树链剖分之后的公共祖先查询，
 *  当两个树节点不在同一个重链，较深的节点自下向上爬道链头父节点，
 *  当二者爬到同一条重链的时候，深度较浅的那个树节点便是二者的公共祖先。
*/ 
int lca(int u, int v){
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]])
            swap(u, v);
        u = ft[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}
```



#### 树上信息维护

```c++
/**
 *  树链剖分之后即可使用线段树维护即可，更新 (u,v) 树节点之间的路径操作与查询公共祖先积分是一样
 *  整一颗子树的编码是恰好等于一段 [id[u],  id[u] + siz[u] - 1] 这段序列
*/ 

void update_path(int u, int v, int c){
    while (top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]])
            swap(u, v);
        update(id[top[u]], id[u], c);
        u = ft[top[u]];
    }
    if(dep[u] < dep[v]) swap(u, v);
    update(id[v], id[u], c);
}

void update_subtree(int u, int c){
    update(id[u], id[u] + siz[u] - 1, c);
}

llong query_path(int u, int v, int k = 1) {
    llong ans = 0;
    while (top[u] != top[v]) {
        if(dep[top[u]] < dep[top[v]])
            swap(u, v);
        ans += query(id[top[u]], id[u]) % p;
        u = ft[top[u]];
    }
    if(dep[u] < dep[v]) swap(u, v);
    ans += query(id[v], id[u]) % p;
    return ans % p;
}

llong query_subtree(int u){
    return query(id[u], id[u] + siz[u] - 1) % p;
}
```

