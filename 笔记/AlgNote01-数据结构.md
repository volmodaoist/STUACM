

### :floppy_disk: 基础数据结构

数据结构本身并不解决问题，其主要作用是存储数据，提供增删改查的接口，

数据结构是数据的容器，真正解决问题的，是在容器上面实现的算法，

每种数据结构都有自己的强项与弱项，



#### (1.1) 内建线性结构

- 静态定长数组 (Fixed-size Array)
- 动态变长数组 (Resizable Array)
- 排序与查找 (Sorting & Searching)
  - 排序使用 `sort`
  -   查找使用 `lower_bound` / `upper_bound` /  `binary_seach`
- 位图 (Bitmask, 通常使用线性结构模拟)
- 大整数 (Big Integer, 通常使用线性结构模拟) 
  - 大整数的运算模拟是一些高级数论算法基础
    - 大整数加法 & 减法
    - 大整数乘法 & 除法

- 双端队列 (Deque, 只用双端队列其实即可模拟 Stack 与Queue)
  - Stack，其中单调栈变体用于优化个别最优化问题的复杂度)
  - Queue，其中单调队列变体用于解决滑动窗口最值或优化最优问题的复杂度)
- **树与图专题中，深度优先搜索与宽度优先搜索也会用到Stack、Queue作为辅助结构！**
- **堆是堆，栈是栈，堆栈这种说法也不知道是谁开创的！**

　



#### (1.2) 内建非线性结构

- 二叉堆优先队列 (Priority Queue)
- 平衡二分查找树 (Balanced Binary Search Tree)
  - 哈希表 (Hash Table)
    - 拉链法
    - 寻址法
  - 普通集合与多重集合 (Set & Multiset)
- 树存储结构 (Tree)
  - 双亲表示法 (使用`vector`记录自己的双亲节点)

  - 孩子表示法 (使用`vector<vi>`记录所有的孩子节点)

  - 兄弟表示法 (使用`vector<vii>`记录第一个孩子与第一个兄弟)

- 图存储结构 (Graph)
  - 连边表 (Edges List, 通常使用 `vector<iii>` 实现)
  - 邻接表 (Adjacency List, 通常使用 `vector<vii>` 实现)
  - 邻接矩阵 (Adjacency Matrix, 通常使用 `AM[N][N]` 实现)

- 大部分的内奸数据结构均可使用数组模拟，其运行效率通常会更高一些







### 🧩并查集

|                             题目                             |                             描述                             |
| :----------------------------------------------------------: | :----------------------------------------------------------: |
|          AC1250. 格子游戏<br/>AC1252. 搭配购买<br/>          |   把实际问题中的对象抽象顶点，利用并查集判环、维护捆绑关系   |
| AC0239. 程序自动分析<br/>AC0241. 银行英雄传说<br/>AC0240. 食物链 | 使用并查集维护可传递的关系，此三题难度逐题递进，AC0241与AC0240 能以边带权并查集或扩展域并查集来解 |
|                                                              |                                                              |



### 🦉维护区间

- 树状数组 (二进制索引树)
- 使用线段树维护区间信息查询问题
  - 为什么要开 4N 空间？
  - 为什么能开 2N 空间？
  - 普通线段树 (下标线段树，维护区间最值或与总和)
  - 权值线段树 (值域线段树，维护区间数据出现频率)
- 可持久化先线段树 (主席树[^HJT]，可持久化结构的基础)
  - 主席树的存储需要动态创建节点，而不可以采用堆式存储
  - 主席树的区间查询 K-th 元素需要用到前缀和思想
  - 主席树的更新与查询需要树上双指针同步搜索
  - 主席树维护值域如果很大则需离散化



|                             题目                             |                             描述                             |
| :----------------------------------------------------------: | :----------------------------------------------------------: |
| LG3372. 线段树1<br/>LG3373. 线段树2<br/>LG6242. 线段树3<br/>LG3374. 树状数组1<br/>LG3368. 树状数组2<br/> | 洛谷模板题汇总，树状数组其实亦可用于维护 Kth 元素，但是洛谷没有相关模板 |
|     LG3919. 可持久化数组<br/>LG3834. 可持久化线段树<br/>     |     能够熟练掌握线段树之后，可以进阶可持久化数据结构模板     |
|                      LG4735. 最大异或和                      |                        可持久化字典树                        |
|                      LG1383. 高级打字机                      | 可持久化数组变体，由于插入、撤销操作均使得长度发生改变，因而需要另开一个数组维护不同版本的数组长度 |
|                     LG3567. KUR-Couriers                     | 值域线段树变体，如果某个元素出现次数严格大于区间长度一半，则其出现的一侧子树元素个数乘二之后严格区间长度 |





### 🌴 单词查找树 (aka 字典树 Trie)

|                             题目                             |                  描述                  |
| :----------------------------------------------------------: | :------------------------------------: |
| AC0143. 最大异或对<br />AC0144. 最长异或值路径<br />AC03485. 最大异或和<br />AC4507. 子数组异或和 | 使用 Trie 走相反零一方向求解最大异或值 |
|                      LG4735. 最大异或和                      |             可持久化字典树             |
|                                                              |                                        |








### 本文批注

[^HJT]: 主席树，也称可持久化线段树，严格来讲也叫 **函数式线段树**，是基于线段树的一种数据结构，是由黄嘉泰引入国内的，尤其名字缩写HJT，因而这个数据结构也称主席树。





### 本文提及的算法模板

#### 带有懒标记的线段树

```c++
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
typedef struct _TreeNode{
    int lo, hi;
    llong v, s, m;
} TreeNode;

/**
 * 本题模板来自于洛谷的 P3373 带有懒标记的乘法与加法线段树
 * 整个模板最为复杂的地方就是向下传递懒标记的操作，注意先乘再加，
 * 每次区间整体数乘更新加法标记的时候，需要连带更新加法标记，
 * 每次向下传递加法标记之前，需要乘以父节点乘法标记，
*/

int v[MAXN], n, m, p;
TreeNode tr[MAXN << 2];

void build(int lo, int hi, int k = 1){
    tr[k].lo = lo, tr[k].hi = hi, tr[k].s = 0, tr[k].m = 1;
    if (tr[k].lo == tr[k].hi) {
        tr[k].v = v[lo] % p;
        return;
    }
    int md = lo + (hi - lo) / 2;
    build(lo, md, lc(k));
    build(md + 1, hi, rc(k));
    tr[k].v = (tr[lc(k)].v + tr[rc(k)].v) % p;
}

// 向下传递懒标记，其中 mtg 代表乘法的标记，atg 代表加法标记，更新标记的时候先乘再加
void push_down(int k){
    if (tr[k].s != 0 || tr[k].m != 1){
        tr[lc(k)].v = (tr[lc(k)].v * tr[k].m + (tr[k].s * (tr[lc(k)].hi - tr[lc(k)].lo + 1))) % p;
        tr[rc(k)].v = (tr[rc(k)].v * tr[k].m + (tr[k].s * (tr[rc(k)].hi - tr[rc(k)].lo + 1))) % p;

        // 先更新乘法标记再更新加法标记
        tr[lc(k)].m = tr[lc(k)].m * tr[k].m % p;
        tr[rc(k)].m = tr[rc(k)].m * tr[k].m % p;
        tr[lc(k)].s = (tr[lc(k)].s * tr[k].m + tr[k].s) % p;
        tr[rc(k)].s = (tr[rc(k)].s * tr[k].m + tr[k].s) % p;

      	// 清空两个标记
        tr[k].s = 0, tr[k].m = 1;
    }
}

void update_mul(int lo, int hi, llong c, int k = 1){
    if(lo <= tr[k].lo && tr[k].hi <= hi){
        tr[k].v = tr[k].v * c % p;
        tr[k].m = tr[k].m * c % p;
        tr[k].s = tr[k].s * c % p;
        return;
    }
    push_down(k);
    int md = (tr[k].lo + tr[k].hi) / 2;
    if(lo <= md) update_mul(lo, hi, c, lc(k));
    if(hi > md)  update_mul(lo, hi, c, rc(k));
    tr[k].v = (tr[lc(k)].v + tr[rc(k)].v) % p;
}

void update_add(int lo, int hi, int c, int k = 1){
    if(lo <= tr[k].lo && tr[k].hi <= hi){
        tr[k].s = (tr[k].s + c) % p;
        tr[k].v = (tr[k].v + c * (tr[k].hi - tr[k].lo + 1)) % p;
        return;
    }
    push_down(k);
    int md = (tr[k].lo + tr[k].hi) / 2;
    if (lo <= md) update_add(lo, hi, c, lc(k));
    if (hi > md)  update_add(lo, hi, c, rc(k));
    tr[k].v = (tr[lc(k)].v + tr[rc(k)].v) % p;
}

llong query(int lo, int hi, int k = 1){
    if(lo <= tr[k].lo && tr[k].hi <= hi){
        return tr[k].v;
    }
    push_down(k);
    int md = (tr[k].lo + tr[k].hi) / 2;
    llong ans = 0;
    if (lo <= md)
        ans = (ans + query(lo, hi, lc(k))) % p;
    if(hi > md)
        ans = (ans + query(lo, hi, rc(k))) % p;
    return ans % p;
}
```



#### 可持久化数组

```c++
#define  lc(x)  (tree[x].lc)
#define  rc(x)  (tree[x].rc)
typedef struct _TreeNode{
    int lo, hi, lc, rc;
    llong val;
}TreeNode;

/**
 * 本题来自于洛谷 P3919 可持久化数组，
 * 可持久化数据结构的各个历史版本是不修改的，所谓修改历史版本其实是基于历史版本再开一个新版本修改，
 * 可持久化的结构几乎都是基于线段树实现的，访问某个历史版本需要借助多棵线段树实现，空间开销较大，
 * 朴素传统线段树需要存储 lo、hi 端点，如需节省空间其实亦可不存，只需传递区间端点参数即可，
 * 朴素做法存起来主要是为了区分待查区间与树节点维护区间，这样不容易搞乱，
*/
TreeNode tree[MAXN << 5];
int A[MAXN], root[MAXN], idx;

void build(int lo, int hi, int &x){
    x = ++idx, tree[x].lo = lo, tree[x].hi = hi;
    if (lo == hi) {
        tree[x].val = A[lo];
        return;
    }
    int md = (lo + hi) / 2;
    build(lo, md, lc(x));
    build(md + 1, hi, rc(x));
    tree[x].val = tree[lc(x)].val + tree[rc(x)].val;
}

// 使用 root[i] 记录ith 版本号对应的树节点, u 代表先前版本号的树节点, v 代表本次更新生成的新版本
void update(int u, int &v, int lo, int hi, int i, int val){
    v = ++idx, tree[v] = tree[u];
    if (lo == hi) {
        tree[v].val = val;
        return;
    }
    int md = (lo + hi) / 2;
    if (i <= md) {
        update(lc(u), lc(v), lo, md, i, val);
    } else {
        update(rc(u), rc(v), md + 1, hi, i, val);
    }
    tree[v].val = tree[lc(v)].val + tree[rc(v)].val;
}

// 通常可持久化只需要实现单索引查询，因而树节点lo、hi，以及建树、更新push_up操作均可省略
llong query(int u,  int i){
    if(tree[u].lo == tree[u].hi && tree[u].lo == i){
        return tree[u].val;
    }
    int md = (tree[u].lo + tree[u].hi) / 2;
    if(i <= md){
        return query(lc(u), i);
    } else {
        return query(rc(u),  i);
    }
}

// 实现区间查询，如果查询区间这张网覆盖了树节点维护的区间则直接返回
llong query(int u,  int lo, int hi){
    if (lo <= tree[u].lo && tree[u].hi <= hi) {
        return tree[u].val;
    }
    llong ans = 0;
		int md = (tree[u].lo + tree[u].hi) / 2;
    if(lo <= md)
        ans += query(lc(u), lo, hi);
    if (hi > md)
        ans += query(rc(u), lo, hi);
    return ans;
}
```



#### 可持久化值域线段树

```c++
#define  lc(x)  (tree[x].lc)
#define  rc(x)  (tree[x].rc)
typedef struct _TreeNode{
    int lc, rc;
    int s;
}TreeNode;

/**
 * 本题模板来自于洛谷 P3834 可持久化线段树
 * 树节点存储的是左右孩子的索引，主席树维护数据的值域，如果值域过大可能需要另外离散化处理，
 * 由于主席树需要重复利用那些未被修改的部分，故无法使用堆式存储，使用 idx 动态建点，
*/
TreeNode tree[MAXN];
int v[MAXM], root[MAXN], idx;

void build(int lo, int hi, int &x){
    x = ++idx; 
    if (lo == hi) {
        return;
    }
    int md = (lo + hi) / 2;
    build(lo, md, lc(x));
    build(md + 1, hi, rc(x));
}

// u 记录先前版本的树节点，v 记录当前版本的树节点
void update(int u, int &v, int lo, int hi, int val){
    v = ++idx, tree[v] = tree[u], tree[v].s++;
    if(lo == hi){
        return;
    }
    int md = (lo + hi) / 2;
    if(val <= md){
        update(lc(u), lc(v), lo, md, val);
    } else {
        update(rc(u), rc(v), md + 1, hi, val);
    }
}

// 返回 kth 元素所在的索引
int query(int u, int v, int lo, int hi, int k){
    if(lo == hi){
        return lo;
    }
    int md = (lo + hi) / 2;
    int s = tree[lc(v)].s - tree[lc(u)].s;
    if (k <= s) {
        return query(lc(u), lc(v), lo, md, k);
    } else {
        return query(rc(u), rc(v), md + 1, hi, k - s);
    }
}
```



### 可持久化字典树

```c++
int v[MAXN], s[MAXN];
int ver[MAXN << 5], root[MAXN << 5], son[MAXN << 5][2], idx;

/**
 * 本题来自洛谷 P4735 最大异或和，
 * 给定一个区间[L,R], 要求找出一个p 使得 A[p]^...^A[n]^x 最大，将其转为前缀和问题之后，
 * 相当于要在[L-1,R-1]之内，找一个 p-1 使得 s[p-1]^s[n]^x 最大值，本题难点在于会在末尾插入新元素，
 * 因而若以每个[1..i]前缀作为版本维护可持久化 Trie，则在搜索[1,R-1]过程中, s.t.版本号大于等于 L-1 即可!
*/

// 使用 u 记录先前版本树节点，使用 v 记录当前版本树节点, 标记当前版本树根的版本号，往下遍历时再逐点标号
void insert(int u, int v, int i){			
    ver[v] = i;
    for (int k = 30; k >= 0; k--){
        int c = s[i] >> k & 1;
      
      // 若非新节点则挂接旧版本，若是新节点则创建新编号
        son[v][!c] = son[u][!c];				
        son[v][c] = ++idx;
      
      	// 新旧版本双指针向下移动，移动之后再设置当前版本新节点编号
        u = son[u][c], v = son[v][c];		
        ver[v] = i;											
    }
}

int query(int u, int lo, int val){
    int ans = 0;
    for (int k = 30; k >= 0; k--) {
        int c = val >> k & 1;
        if(ver[son[u][!c]] >= lo){
            u = son[u][!c], ans += 1 << k;
        } else {
            u = son[u][c];
        }
    }
    return ans;
}
```
