### 📒本章纲要

线性表是指逻辑上面元素彼此之前前后连续，除了首尾元素之外，所有元素均有唯一前驱与后继的结果，其中首元仅有后继，尾元仅有前驱。因而逻辑概念上面，线性表不等于数组，但是物理结构上面常用数组实现线性表，并且字符串也是一种线性表，其中蕴含的学问更多，本章暂且不讲！

- 线性结构与优化

  - 线性表与字符串
  - 双指针技巧
  - 滑动窗口技巧

  - 离散化技巧

- 使用单调结构维护线性表信息
  - 使用单调栈维护数列某个元素的前驱值、后继值；
  - 使用单调队列维护数列某个区间最小值、最大值；

- 查询线性表区间信息
  - 前缀和数组（离散积分数组）
  - 邻项差数组（离散差分数组）
  - 稀疏表快速解决 RMQ







### 查询线性表区间信息

|             题目              | 思路描述 |
| :---------------------------: | :------: |
| LC0862. 总和至少 K 最短子数组 |          |
|                               |          |
|                               |          |



### 基础数据结构快速实现

我们上面提到了线性结构，以及基于线性结构的一些技巧，其实非线性结构的物理存储大多也是基于线性数据结构实现的，本节罗列了一些内建的，或者非内建但是基于 STL 提供的向量容器能够快速实现的基础数据结构，其实所有的这些结构，包括仅存储简单元素的哈希表与集合，也都可以使用数组模拟实现。

- **内建的数据结构**
  
  - 静态定长数组 (Fixed-size Array)
  - 动态变长数组 (Resizable Array)
  - 排序与查找 (Sorting & Searching)
    - 排序使用 `sort`
    - 查找使用 `lower_bound` / `upper_bound` /  `binary_seach`
  - 位图 (Bitmask, 通常使用线性结构模拟)
  - 大整数 (Big Integer, 通常使用线性结构模拟) 
    - 大整数的运算模拟是一些高级数论算法基础
      - 大整数加法 & 减法
      - 大整数乘法 & 除法
  - 双端队列 (Deque, 只用双端队列其实即可模拟 Stack 与Queue)
  
- 二叉堆优先队列 (Priority Queue)

- 平衡二分查找树 (Balanced Binary Search Tree)

  - 多重集合与普通集合 (Multiset & Set)
  - 哈希表 (Hash Table)
    - 拉链法
    - 寻址法

- **非内建的数据结构**

  - 树存储结构 (Tree)
    - 双亲表示法 (使用`vector`记录自己的双亲节点)

    - 孩子表示法 (使用`vector<vi>`记录所有的孩子节点)

    - 兄弟表示法 (使用`vector<vii>`记录第一个孩子与第一个兄弟)

  - 图存储结构 (Graph)
    - 连边表 (Edges List, 通常使用 `vector<iii>` 实现)
    - 邻接表 (Adjacency List, 通常使用 `vector<vii>` 实现)
    - 邻接矩阵 (Adjacency Matrix, 通常使用 `AM[N][N]` 实现)

  





### 🙈关于STL工具的奇技淫巧

```c++
// 简化编码的宏定义
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))

// 枚举排列组合,复杂度O(n!)
next_permutation(a,a+n);
prev_premutation(a,a+n);

// 对于容器的所有元素执行某个函数
for_each(ALL(container), func);

// 向量容器转为堆容器
make_heap(ALL(vec));
push_heap(ALL(vec)) + pop_heap(ALL(vec));
sort_heap(ALL(vec));

// 检查有序性、检查有序性并返回第一个破坏有序性的元素迭代器
is_sorted(ALL(container));
is_sorted_until(ALL(container));

// 获取容器的最大值与最小值 max_element 与 min_element
cout << max_element(a, a + 5) << *max_element(a, a + 5) << endl;
cout << min_element(a, a + 5) << *min_element(a, a + 5) << endl;

// 类似于Python当中的负索引迭代器
vector <int> v = {1, 2, 3, 4, 5};
cout << v.end()[-1] << ... <<  v.end()[-5] << endl;
```





### 常用的魔法数字

| 魔法数字  |                            用途                             |
| :-------: | :---------------------------------------------------------: |
|   0x7f    |        memset(dp, 0x7f, sizeof(dp)) 初始化一个极大值        |
|   0x3f    |        memset(dp, 0x3f, sizeof(dp)) 初始化一个较大值        |
|   0xc0    |        memset(dp, 0xc0, sizeof(dp)) 初始化一个较小值        |
|   0x80    |        memset(dp, 0x80, sizeof(dp)) 初始化一个极小值        |
| 31 (32-1) | `s[i] & 31` 相当于 `s[i] - 'a' + 1`，也即 1-base 计数字母序 |
| 63 (64-1) | `s[i] & 63` 相当于 `s[i] - 'A' + 1`，也即 1-base 计数字母序 |

