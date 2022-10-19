### 🎄本章纲要

- 二叉树具有何种性质
  - 如何建立一棵二叉树
  - 如何遍历一棵二叉树，DFS: 前序/中序/后序，以及 BFS 层序
  
    - 普通递归遍历 & 带有空针标记的栈遍历
    - 如何推广多叉树的中序遍历 (参考树重心问题)
    - 如何根据中序遍历序列与另外一个序列反推树结构
    - 其它二叉树递归技巧
      - 同层跨子树如何连接
      - 同子树跨层如何连接
  - 如何建立一棵(多叉)无根树
  
- 二叉树的基本属性
  
    - 树直径 (如果所有权值均为正数，所有直径的中点都重合)
      - 没有负边权 两次DFS 
      - 含有负边权 树形DP
    - 树中心：使树节点可到达的最远距离最近的一个树节点
    - 树重心：使树节点可分割的最大子树最小的一个树节点
    - 最近公共祖先
      - 树上倍增查询 LCA
      - 树链剖分查询 LCA
      - TarjanLCA
    - 树形动态规划
    - 树链剖分 (※ 重中之重，根据什么剖分并无唯一标准，需要面向场景选择)
      - 轻重或长短剖分
      - 访问次数剖分
    - 树上信息维护(树链剖分+线段树/平衡树)
    
- 如何处理基环树

    



### 🪵树链剖分

树链剖分主要采用轻重链剖分，完成剖分之后：

(1) 树会被分成若干重链; 

(2) 轻儿子必然是每条重链的顶点；

(3) 任意一条路径会被分成重链，数量不多于 $O(\log N)$；

算法流程方面需要两次 dfs 获取不同的信息，一次建树获取基本信息，一次分解获取重链轻链。经过这种转化得到的一条重链，其上每个节点的编号是整形连续的，此时能用线段树维护树上信息。











### 🐉基环树

严格来说，基环树并非树结构，而是图结构。基环树是在树上面添加一个环，仅有一个环形结构的图结构称为基环树。基环树可以视为以环点为根的若干子树构成。基环树一般不单独出现，会结合树形dp考察，其主要解法是拆边成林，并对基环树森林进行树形dp。

|          题目          |                           思路描述                           |
| :--------------------: | :----------------------------------------------------------: |
| LG1352. 没有上司的舞会 | 相邻节点不可以同时获取，树型打家劫舍[^打家劫舍]问题，也是LG2607 前置题目， |
|      LG2607. 骑士      | 拆掉环上连边，找出一对节点，再对两个节点跑一趟树形 dp 取二者最大值即可 |
|     LG1399. 快餐店     |                        基环树最小直径                        |
|      LG5022. 旅行      | 如果是树直接对边存储的表顶排序，若为基环树则暴力删边，然后深搜 |





### ⚔️树遍历技巧选讲

|                             题目                             |                思路描述                |
| :----------------------------------------------------------: | :------------------------------------: |
| LC0116.填充每个节点的右侧指针<br/>LC0117.填充每个节点的右侧指针II<br/> | 当前层 next 指针域更新下一层跨子树连接 |
|                                                              |                                        |
|                                                              |                                        |



### ⚔️树形动态规划选讲

以下三道题是树形动态规划的基础，很多问题均是下列问题的延伸与拓展！

|        题目        |                           思路描述                           |
| :----------------: | :----------------------------------------------------------: |
| AC1072. 树最长路径 |        树直径模板题，由于含有负权，故仅能使用树形 dp         |
|  AC1073. 树的中心  | 树中心模板题，需要使用子节点更新父节点信息，也要用到父节点更新子节点信息 |
|  AC0846. 树的重心  |  树重心模板题，每次递归遍历子节点，当回传的时候更新最大子树  |





### 🦉本文提到的算法模板

####  二叉树遍历

```c++
void xxx_orderTraversal(TreeNode* root){
  	if(root == NULL)
      	return;
  // 前序遍历...
  xxx_orderTraversal(root->left);
  // 中序遍历...
  xxx_orderTraversal(root->right);
  // 后序遍历...
}
```

```c++
// 使用栈模拟递归的过程，由于LIFO特点，压入节点的时候记得顺序要反转一下
vector<int> xxx_orderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> stk;
    if(root != NULL)
        stk.push(root);
    while(!stk.empty()){
        auto curr  = stk.top(); stk.pop();
        if(curr != NULL){
          	// 后序遍历...
            if(curr->right) stk.push(curr->right);
          	// 中序遍历...
            if(curr->left) stk.push(curr->left);
            // 前序遍历...
        }else{
            curr = stk.top(); stk.pop();
            ans.push_back(curr->val);
        }
    }
    return ans;
}
```



#### 树直径问题

```c++
/** 方法 1:  两次dfs 计算树结构的直径
 *  记录第一次能够到达的最远处，然后再从最远处再做一次深搜遍历，需要注意这种方法边权不允许存在负权边，
 *  其实只要出现负数，很多方法都因单调性或单向性等遭破坏而无法继续使用，例如滑动窗口维护区间和 S[L,R] = K；
 */
vector<int> edges[MAXN];
int d[MAXN], farthest = 0;

void dfs(int u, int father) {
    for (int v: edges[u]){
        if(v == father)
            continue;
        d[v] = d[u] + 1;
        if(d[farthest] < d[v]){
            farthest = v;
        }
        dfs(v, u);
    }
}

// 不知道根节点也无所谓，第一趟随便选择一个顶点出发即可
void solve(){
   	dfs(1, 0);
  	d[farthest] = 0;
  	dfs(farthest, 0);
	  printf("%d\n", d[farthest]);
}
```

```c++
/** 方法 2:  树形动态规划
 *  记录树节点能够到达的最远距离与次远距离，然后最远与次远相加之后更新一下直径，
 *  这种方法相当于枚举了以每个树节点能构成的所有直径，对于含有负权边的情况同样适用；
 */
vector<int> edges[MAXN];
int d1[MAXN], d2[MAXN], d = 0;

void dfs(int u, int father) {
    d1[u] = d2[u] = 0;
    for (int v : edges[u]) {
        if(v == father)
            continue;
        dfs(v, u);
        int t = d1[v] + 1;
        if(t > d1[u]){
            d2[u] = d1[u], d1[u] = t;
        }else if(t > d2[u]){
            d2[u] = t;
        }
        d = max(d, d1[u] + d2[u]);
    }
}
```



#### 树中心问题

```c++
/**
 * 核心思路是跑两次dfs，这种方法适用于无负权边的情况，
 * 第一次自底向上预处理得到向下移动的最远距离与次远距离，第二次自顶向下预处理向上移动的最远距离，
*/
void dfs_bottom2top(int u, int father){
    d1[u] = d2[u] = 0;
    for(auto &[v,w]: edges[u]){
        if(v == father)
            continue;
        dfs_bottom2top(v, u);
        int t = w + d1[v];
        if(t > d1[u]){
            d2[u] = d1[u], d1[u] = t, bg[u] = v;
        }else if(t > d2[u]){
            d2[u] = t;
        }
    }
}

void dfs_top2bottom(int u, int father){
    for(auto& [v, w]: edges[u]){
        if(v == father)
            continue;
        if(v == bg[u]){
            up[v] = max(up[u], d2[u]) + w; // 如果当前顶点落在父节点 u 最长路径上面，使用次远距离更新
        }else{
            up[v] = max(up[u], d1[u]) + w; // 如果当前顶点不在父节点 u 最长路径上面，使用最远距离更新
        }
        dfs_top2bottom(v, u);
    }
}

```



#### 树重心问题

```c++
// 主要思路就是向下递归，当递归回传的时候更新当前节点挂接的各个子树大小，找出一个能使最大子树最小的节点，
vector<int> edges[MAXN];
int n, a, b, pos, ans = INT_MAX, siz[MAXN];

void dfs(int u, int father){
    int mxs = 0; siz[u] = 1;		
    for(int v: edges[u]){
        if(v == father) 
          	continue;
        dfs(v, u);
        mxs = max(mxs, siz[v]); // 当前节点底部挂接的各个子树的大小，其实就是各子节点为根的向下生长子树
        siz[u] += siz[v];
    }
    mxs = max(mxs, n - siz[u]); // 当前节点顶部挂接的一个子树的大小，其实就是以父节点为根的向上生长子树
    if(mxs < ans){
        ans = mxs, pos = u;		  
    }
}
```



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
 *  整颗子树的编码是恰好等于一段 [id[u],  id[u] + siz[u] - 1] 这段序列，下面的update与query来自线段树！
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






### 本文批准

[^打家劫舍]: LeetCode 上面搜索「打家劫舍」即可找到这个系列的问题，大意是说相邻元素不可以同时获取，本题有着线形、环形与树形三种变体，是非常经典面试题。
