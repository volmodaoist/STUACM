### 📙本章纲要

- 维护区间 (区间加总/连乘/异或/最值/kth元素)
  - 简单回忆前面学过一些结构并分析其在不足之处

    - 前缀和与邻项差
    - 稀疏表
    - 堆
  
- 维护区间树形结构家族

  - 树状数组 (这是一颗残缺的线段树)

    - 单点修改 + 区间查询
    
    - 区间修改 + 区间查询
    
    - 最常见的几种线段树
    
    - 非递归线段树[^zkw]
      - 带有懒标记的线段树 (区间覆盖式线段树)
      
    - 标记永久化的线段树 (区间相等式线段树)
    
    - 平衡查找树 BBST
      - 使用值域线段树亦可实现平衡树维护区间翻转之外的功能
      
      - 自平衡二分搜索树，也称伸展树 Splay[^Tarjan]
      
      - 树堆 Treap
      
        - 带旋转 Treap
      
        - 无旋转 FHQ Treap[^FHQ]
      
    
  - 链切树 **Link-Cut-Tree**
  
- 线段树各种变体精讲
  - 使用线段树维护区间信息查询问题
    - 常见线段树应用 (基本加乘、01 序列异或、正弦与余弦、最大子段和、区间矩阵连乘积)
      - 普通线段树 (下标线段树，维护区间最值或与总和)
      - 权值线段树 (值域线段树，维护区间数据出现频率)
    - 可持久化先线段树 (主席树[^HJT]，可持久化结构的基础)
      - 主席树的存储需要动态创建节点，而不可以采用堆式存储
      - 主席树的区间查询 K-th 元素需要用到前缀和思想
      - 主席树的更新与查询需要树上双指针同步搜索
      - 主席树维护值域如果很大则需离散化
    - 其它可持久化数据结构
      - 可持久化字典树
      - 可持久化平衡树
      - 可持久化并查集

### ⚔️残缺的线段树

前缀和、邻项差、稀疏表、树状数组均可视为残缺的线段树，换句话说，能用以上数据结构来写的题目，均可使用线段树来做，只不过一般用不着大炮打蚊子。

|                     题目                     |                      描述                      |
| :------------------------------------------: | :--------------------------------------------: |
| LG3374. 树状数组1<br/>LG3368. 树状数组2<br/> |          来自洛谷的几个树状数组模板题          |
|             LC2104. 子数组范围和             | 稀疏表模板题，本题数据量较小，直接暴力同样能过 |
|                                              |                                                |



### ⚔️线段树家族例题选讲

|                             题目                             |                             描述                             |
| :----------------------------------------------------------: | :----------------------------------------------------------: |
| LG3372. 线段树1<br/>LG3373. 线段树2<br/>LG6242. 线段树3<br/> |                  来自洛谷的几个线段树模板题                  |
|               LG1816. 忠诚<br />LG2068. 统计和               |           线段树裸题，适合用来练习 zkw 线段树板子            |
|     LG1471. 方差<br/>LG2894. Hotel<br/>LG3870. 开关<br/>     |                        线段树模版变体                        |
|                       LG4588. 数学运算                       | 初看以为是一个乘法逆元问题，但是数据与模数不互质，本题应按时间轴建立线段树维护 |
|     LG3919. 可持久化数组<br/>LG3834. 可持久化线段树<br/>     | 能够熟练掌握线段树之后，可以进阶可持久化数据结构模板，其中可持久化数组是对一个简化版可持久化线段树 |
|                        LG1198. 最大数                        |    本题解法众多，使用可持久化线段树没有什么思维含量，能秒    |
|                      LG1383. 高级打字机                      | 可持久化数组变体，由于插入、撤销操作均使得长度发生改变，因而需要另开一个数组维护不同版本的数组长度 |
|                     LG3567. KUR-Couriers                     | 值域线段树变体，如果某元素出现次数大于区间长度一半，则其所在子树元素数乘二之后严格大于区间长度 |
|                       LG2023. 维护序列                       |                                                              |
|                     LC0053. 最大子数组和                     | 本题是经典的贪心、动规问题，使用线段树亦可维护最大子段和，且本题只需建树 |



### ⚔️平衡树家族例题选讲

不同于 AVL、红黑树，Splay 通过双旋操作保持均摊复杂度 $O(\log N)$，由于复杂度是均摊的，并非真正意义的平衡，因而Splay 无可持久化，可持久化最常用的平衡树是 FHQ Treap。平衡树的主要作用是查询元素 rank、以及 kth 元素，这个需求亦可使用可持久化值域线段树。

- Splay 需要注意的细节	
  - 此端与彼端不可写死为左右端
  - 每个操作结束之后都要伸展一趟
  - 查找与插入内部进行元素比较走向左侧或右侧
  - 需要插入正负无穷大哨兵解决最值的前驱与后继
- Treap 需要注意的细节
  - 每次分裂之后必须合并，且注意更新根节点
  - 合并是按照随机生成的 key 关键字合并，元素越多越不容易发生退化
  - 重复元素会以不同节点形式会出现于左侧子树，因而获取 kth 元素的判定不同于 Splay

|          题目          |                           思路描述                           |
| :--------------------: | :----------------------------------------------------------: |
|   LG3369. 普通平衡树   |      模板题，维护kth、rank、前驱、后继，动态插点与删点       |
|   LG3369. 文艺平衡树   |        模板题，通过懒标记改造平衡树，使其维护序列翻转        |
| LC0295. 数据流的中位数 | 使用平衡树维护kth元素，然后求平均值，或者使用一个两个堆来确定中位数 |

我们经常使用平衡树维护区间 kth 元素，特别地，如果这个数恰好是全局的中位数，也即我们处于需要动态维护数组中位数这样一个场景的时候，我们不需要使用平衡树，只要是有一个大根堆与一根小根堆即可。或者使用双指针配合内置的多种集合维护中位数，因为其底层就是红黑树。





### 🦉文本提及线段树算法模板

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



#### 标记永久化的线段树

```c++
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
typedef struct _TreeNode{
    int lo, hi;
    llong val, tag;
} TreeNode;

/**
 * 朴素的线段树采用了区间覆盖式的写法，标记永久化的线段树通常使用区间相等的写法,
 * 由于覆盖式写法更加通用，可扩展更好，故必须掌握，对于纯粹加法或乘法，标签永久化方法优点是代码量少，
 * 然而对于 洛谷 P3373 这道加乘混合的区间维护线段树模板题，使用下推标记的方法代码量更少，逻辑更容易实现！
*/ 

int A[MAXN];
TreeNode tree[MAXN << 1];

void build(int lo, int hi, int k = 1){
    tree[k].lo = lo, tree[k].hi = hi, tree[k].tag = 0;
    if (tree[k].lo == tree[k].hi) {
        tree[k].val = A[lo];
        return;
    }
    int md = lo + (hi - lo) / 2;
    build(lo, md, lc(k));
    build(md + 1, hi, rc(k));
    tree[k].val = tree[lc(k)].val + tree[rc(k)].val;
}

// 如果更新区间恰好等于当前树节点维护的区间，则把元素加到标签上面，否则加到数值上面
void update(int lo, int hi, int c, int k = 1) {
    if (tree[k].lo == lo && tree[k].hi == hi) {
        tree[k].tag += c;
        return;
    }
    tree[k].val += (hi - lo + 1) * c;
    int md = (tree[k].lo + tree[k].hi) / 2;
  	
  	// 下列的更新操作的 hi <= md 与 lo > md 看起来有点诡异，
    // 其实这里的 md 是指树节点维护区间的中值，lo、hi 是更新区间的两端
    if (hi <= md) {
        update(lo, hi, c, lc(k));
    }else if(lo > md){
        update(lo, hi, c, rc(k));
    } else {
        update(lo, md, c, lc(k)), update(md + 1, hi, c, rc(k));
    }
}


// 使用一个变量在递归过程中传递一下树上路径的标签和，相当于 push_down 过程
llong query(int lo, int hi, llong c, int k = 1){
    c += tree[k].tag; 
    if(tree[k].lo == lo && tree[k].hi == hi){
        return tree[k].val + c * (hi - lo + 1);
    }
    // 同理于 update，lo、hi 是查询区间的两端，md 是指树节点维护区间的中值，二者描述的主体不一样
    int md = (tree[k].lo + tree[k].hi) / 2;
    if (hi <= md) {
        return query(lo, hi, c, lc(k));
    } else if (lo > md) {
        return query(lo, hi, c, rc(k));
    }else{
        return query(lo, md, c, lc(k)) + query(md + 1, hi, c, rc(k));
    }
}
```





#### 非递归单点修改线段树

```cpp
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)

/**
 * 非递归线段树也称 zkw 线段树，最大的优点就是代码量很少，写起来有一种在写树状数组的感觉，
 * 本题模版来自洛谷 P2068，在做本题之前可以尝试写一下 P4715
*/
int n, m, N = 1, v[MAXN];
llong tree[MAXN << 2], mark[MAXN << 2];

void build(){
    for (N = 1; N <= n; N <<= 1);
    for (int i = 1; i <= n; i++)
        tree[i + N] = v[i];
    for (int i = N - 1; i; --i){
        tree[i] = tree[lc(i)] + tree[rc(i)];
    }
}

void update(int x, int d){
    for (int i = x + N; i; i >>= 1){
      	tree[i] += d;
    }
}

int query(int lo, int hi){
    int ans = 0;
    for (lo += N - 1, hi += N + 1; lo ^ hi ^ 1; lo >>= 1, hi >>= 1){
        if (~lo & 1) ans += tree[lo ^ 1]; 
        if (hi & 1) ans += tree[hi ^ 1]; 
    }
    return ans;
}
```



#### 非递归区间修改线段树

```c++
/**
 * 如果 zkw 线段树需要支持区间修改，则需另开一个标记数组 mark，由于下推标签不方便，故采用标签永久化手段，
 * 模板中的加法也能改成乘法、最值，但是如果涉及加乘混合运算，标签永久化实现起来会很麻烦，
*/

void update(int lo, int hi, int val){
    int len = 1, cntl = 0, cnth = 0;
    for (lo += N - 1, hi += N + 1; lo ^ hi ^ 1; lo >>= 1, hi >>= 1, len <<= 1) {
        tree[lo] += cntl * val, tree[hi] += cnth * val;
        if(~lo & 1) tree[lo ^ 1] += val * len, mark[lo ^ 1] += val, cntl += len;
        if(hi & 1) tree[hi ^ 1] += val * len, mark[hi ^ 1] += val, cnth += len;
    }
    while(lo){
        tree[lo] += cntl * val, tree[hi] += cnth * val;
        lo >>= 1, hi >>= 1;
    }
}

llong query(int lo, int hi){
    llong ans = 0;
    int len = 1, cntl = 0, cnth = 0;
    for (lo += N - 1, hi += N + 1; lo ^ hi ^ 1; lo >>= 1, hi >>= 1, len <<= 1) {
        ans += cntl * mark[lo] + cnth * mark[hi];
        if (~lo & 1) ans += tree[lo ^ 1], cntl += len;
        if (hi & 1) ans += tree[hi ^ 1], cnth += len;
    }
    while(lo){
        ans += cntl * mark[lo] + cnth * mark[hi];
        lo >>= 1, hi >>= 1;
    }
    return ans;
}
```



### 🦉文本提及的平衡树算法模板

#### BBST-SplayTree

```c++
/**
 * 本题来自洛谷 P3369，维护数列的动态插入、删除、按排名取值、按值给排名、获取前驱与后继！
 * 甚至反转某段区间的元素，这些功能需要借助平衡树 Splay 实现，其核心操作在于旋转与伸展(rotate/splay);
*/

typedef struct _TreeNode{
    int v, p, s[2];
    int siz, cnt;
} TreeNode;

int root, idx;
TreeNode tr[MAXN];

// SplayTree允许重复元素存在，其处理方式是使用 cnt 记录重复元素出现了多少次
void push_up(int x){
    tr[x].siz = tr[tr[x].s[0]].siz + tr[tr[x].s[1]].siz + tr[x].cnt;
}

/**
 * 变量 ci、bi、di 分别代表此端、彼端、顶端，
 * 例如 x 如果位于左端，此端即左端，彼端即右端，反之此端为右端，彼端为左端，
 * 顶端是指 x 父节点 y 挂在祖先节点 z 哪一侧 (x <- y <- z)，0 代表左侧，1 代表右侧!
*/
void rotate(int x){
    int y = tr[x].p, z = tr[y].p;
    int ci = tr[y].s[1] == x, di = tr[z].s[1] == y, bi = ci ^ 1;

    int t = tr[x].s[bi];
    tr[y].s[ci] = t, tr[t].p = y;
    tr[x].s[bi] = y, tr[y].p = x;
    tr[z].s[di] = x, tr[x].p = z;

    // 自顶向上更新信息
    push_up(y), push_up(x);
}

/** 
 * 伸展操作访问节点 x, 并把 x 转到根节点，此处我们虚设 0 作为根节点的父节点
 *    如果 k > 0 则把 x 转到 k 子节点位置，
 *    如果 k = 0 则把 x 转到 root 根节点位置，
*/
void splay(int x, int k){
    while (tr[x].p != k){
        int y = tr[x].p, z = tr[y].p;
        if (z != k){
            (tr[y].s[0] == x) ^ (tr[z].s[0] == y) 
                ? rotate(x) : rotate(y);
        }
        rotate(x);
    }
    if(k == 0) root = x;
}


/**
 * 查找 v 所在节点并把这个节点转到根节点，
 * 之所以要做这趟旋转，是因为如果这个节点不存在，那么退出 find 函数的时候，
 * 此时 x 指向的位置非常最接近 v，这条性质能够帮助我们快速计算这个元素的前驱或后继！
*/
int find(int v){
    int x = root;
    while (tr[x].s[v > tr[x].v] && v != tr[x].v){
        x = tr[x].s[v > tr[x].v];
    }
    splay(x, 0);
    return root;
}

int get_prev(int v){
    int x = find(v);
    if (tr[x].v < v) {
        return x;
    }
    x = tr[x].s[0];
    while (tr[x].s[1]) x = tr[x].s[1];
    return x;
}

int get_succ(int v){
    int x = find(v);
    if (tr[x].v > v){
        return x;
    }
    x = tr[x].s[1];
    while(tr[x].s[0]) x = tr[x].s[0];
    return x;
}


// 务必注意括号运算符里面比较运算是否正确！
void ins(int v){
    int x = root, p = 0;
    while(x && tr[x].v != v){
        p = x, x = tr[x].s[v > tr[x].v];
    }
    if(x){
        tr[x].cnt++;
    }else{
        x = new_node(p, v);
        tr[p].s[v > tr[p].v] = x;
    }
    splay(x, 0);
}

// 直接删除比较麻烦，因而先找前驱和后继，利用它们把待删除的节点夹到叶子节点，
// 又因为最小值无前驱，最大值无后继，为了减少特判，简化代码，故在树中插入正负无穷大作为哨兵，
void del(int v){
    int prev = get_prev(v);
    int succ = get_succ(v);
    splay(prev, 0), splay(succ, prev);
    int temp = tr[succ].s[0];
    if(tr[temp].cnt > 1){
        tr[temp].cnt--, splay(temp, 0);
    }else{
        tr[succ].s[0] = 0, splay(succ, 0);
    }
}

// 由于左右子树分别存在负无穷、正无穷哨兵，因而查找元素排在第几名的的时候无需进行+1操作
int get_rank(int v){
    return tr[tr[find(v)].s[0]].siz;
}

int get_val(int k){
    int x = root;
    while(1){
        int s = tr[x].s[0];
        if(tr[s].siz + tr[x].cnt < k){
            k -= tr[s].siz + tr[x].cnt;
            x = tr[x].s[1];
        }else if(tr[s].siz >= k){
            x = tr[x].s[0];
        }else break;
    }
    splay(x, 0);
    return tr[x].v;
}
```



#### BBST-Treap

```c++
// Treap 允许重复元素存在，其处理方式是使用规定左子树小于等于，右子树严格大于
#define lc(x)  (tr[x].lc) 
#define rc(x)  (tr[x].rc) 
typedef struct _TreeNode{
    int lc, rc;
    int val, key, siz;
} TreeNode;

int root, idx;
TreeNode tr[MAXN];

/**
 * 本题来自洛谷 P3369，维护数列的动态插入、删除、按排名取值、按值给排名、获取前驱与后继！
 * 甚至反转区段区间的元素，除了Splay 亦可借助代码更少的 Treap 实现，其核心操作在于分裂与合并(split/merge);
*/
int new_node(int v){
    tr[++idx].val = v, tr[idx].key = rand(), tr[idx].siz = 1;
    return idx;
}

void push_up(int p){
    tr[p].siz = tr[lc(p)].siz + tr[rc(p)].siz + 1;
}

// 使用元素大小作为分裂依据，左侧子树小于等于v，右侧子树严格大于v 
void split(int p, int v, int &x, int &y){
    if(!p){
        x = 0, y = 0;
        return;
    }
    if(tr[p].val <= v){
        x = p;
        split(rc(x), v, rc(x), y);
    }else{
        y = p;
        split(lc(y), v, x, lc(y));
    }
    push_up(p);
}

// 按照随机生成的 key 大小进行排序，元素越多退化成为链表的概率就越小
int merge(int x, int y){
    if(!x || !y) return x + y;
    if(tr[x].key < tr[y].key){
        rc(x) = merge(rc(x), y);
        push_up(x); return x;
    } else {
        lc(y) = merge(x, lc(y));
        push_up(y); return y;
    }
}

void ins(int v){
    int x, y, z;
    split(root, v, x, z);
    y = new_node(v);
    root = merge(merge(x, y), z);
}

void del(int v){
    int x, y, z;
    split(root, v, x, z), split(x, v - 1, x, y);
    y = merge(lc(y), rc(y));
    root = merge(merge(x, y), z);
}

// 查找第K大元素是哪一个树节点
int get_kth(int p, int k){
    if(k <= tr[lc(p)].siz){
        return get_kth(lc(p), k);
    }else if(k == tr[lc(p)].siz + 1){
        return p;
    }else{
        return get_kth(rc(p), k - tr[lc(p)].siz - 1);
    }
}

// 查找元素v排在树中第几名，排名定义为小于当前元素的数据个数 + 1 
int get_rank(int v){
    int x, y, z;
    split(root, v - 1, x, y);
    int ret = tr[x].siz;
    root = merge(x, y);
    return ret;
}

// 因为约定左树小于等于，所以分裂要用 v - 1
int get_prev(int v){
    int x, y;
    split(root, v - 1, x, y);
    int p = get_kth(x, tr[x].siz);
    root = merge(x, y);
    return p;
}

// 因为约定右树严格大于，所以分裂使用 v 即可
int get_succ(int v){
    int x, y;
    split(root, v, x, y);
    int p = get_kth(y, 1);
    root = merge(x, y);
    return p;
}
```





#### BBST-01Trie

```c++
// 同时满足二叉平衡查找树、线段树、平衡树性质，具有极高的可扩展性， 
// 与一般 Trie 一样，使用零代表空指针，同时虚设一个超级节点 idx = 1 作为所有元素第一层，
int idx = 1;
int tr[MAXN << 5][2], siz[MAXN << 5];

int new_node(){
    siz[++idx] = tr[idx][0] = tr[idx][1] = 0;
    return idx;
}

// 插入元素 x，插入数量 c， 如果需要删除则设 c = -1
void ins(int x, int c){
    int u = 1;
    for (int i = 30; i >= 0; i--){
        int v = (x >> i) & 1;
        if(!tr[u][v]){
            tr[u][v] = new_node();
        }
        u = tr[u][v];
        siz[u] += c;
    }
}

int get_kth(int k){
    int u = 1, ans = 0;
    for (int i = 30; i >= 0; i--){
        if (siz[tr[u][0]] >= k){
            u = tr[u][0];
        }else{
            ans |= (1 << i), k -= siz[tr[u][0]];
            u = tr[u][1];
        }
    }
    return ans;
}

int get_rank(int v){
    int u = 1, ans = 0;
    for (int i = 30; i >= 0; i--){
        if ((v >> i) & 1){
            ans += siz[tr[u][0]];
            u = tr[u][1];
        }else{
            u = tr[u][0];
        }
    }
    return ans;
}

/**
 *     注意 01-Trie 平衡树的 rank 是从零开始计算的，但是 kth 从一开始计算，本题给出 1-base 序列，
 *  因此 rank 返回之前需要 + 1，同时由于 01-Trie 返回节点所在的索引是不太方便的，其获取前驱与后继
 *  主要依赖 rank、kth 两个操作，前驱也即寻找 v 前一个排名，后继也即寻找 v + 1 第一个排名，记得+1
 */ 

int get_prev(int v){
	return get_kth(get_rank(v));
}

int get_succ(int v){
    return get_kth(get_rank(v + 1) + 1);
}
```







### 🦉本文提及的可持久化结构模板


#### 可持久化元素线段树

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
    if(lo <= md) ans += query(lc(u), lo, hi);
    if (hi > md) ans += query(rc(u), lo, hi);
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
 * 本题模板来自于洛谷 P3834 可持久化线段树，但是本题线段树是一个值域线段树，
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



#### 可持久化字典树

```c++
int v[MAXN], s[MAXN];
int ver[MAXN << 5], root[MAXN << 5], son[MAXN << 5][2], idx;

/**
 * 本题来自洛谷 P4735 最大异或和，
 * 给定一个区间 [L,R], 要求找出一个p 使得 A[p]^...^A[n]^x 最大，将其转为前缀和问题之后，
 * 相当于要在 [L-1,R-1] 之内，找一个 p-1 使得 s[p-1]^s[n]^x 最大值，本题难点在于会在末尾插入新元素，
 * 因而若以每个 [1..i] 前缀作为版本维护可持久化 Trie，则在搜索[1,R-1]过程中, s.t.版本号大于等于 L-1 即可!
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







### 本文批注

[^HJT]: 主席树，也称可持久化线段树，严格来讲也叫 **函数式线段树**，是基于线段树的一种数据结构，是由黄嘉泰引入国内的，尤其名字缩写HJT，因而这个数据结构也称主席树。

[^ZKW]:  非递归线段树，张昆伟发明，自底向上的建树只需要2N空间，比起传统自顶向下的线段树更加节省空间，在对计算几何的研究过程中诞生了很多用于区间查询、穿刺查询的数据结构，其中线段树是用于高维正交查询的 KD-Tree 特例，主要用于一维空间的几何统计。
[^Tarjan]: 伸展树Splay 是一种平衡二叉树，通过不停的旋转某个节点到根节点，使得整棵树仍然满足BST性质，这个结构是由Daniel Sleator 与 Robert Tarjan 发明的。
[^FHQ]: 树堆 Treap 是由 Tree 与 Heap两个单词组合而成，这个数据结构是由范浩强发明的，代码量相较于 Splay 更少，而且能够可持久化，故在比赛中更为常用，
