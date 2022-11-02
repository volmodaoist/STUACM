### 📕本章纲要

如果某个模拟题的给定数据范围非常小，千万别做分类讨论，因为肯定会有很多的刁钻的样例！

- 如何选择枚举变量
- 搜索算法
  - 深度优先算法
    - 回溯穷举思想(排列与组合问题)
      - 枚举排列
      - 枚举组合
  - 宽度优先算法
    - 增量构造思想
    - 迷宫搜索问题
  - 搜索剪枝技巧
- 高级搜索算法





### ⚔️枚举题选讲

|            题目            |                           思路描述                           |
| :------------------------: | :----------------------------------------------------------: |
| LC2423. 删除字符使频率相同 | 不做分类讨论，直接双重循环，内循环使用哈希表判断是否存在可行解 |
|                            |                                                              |
|                            |                                                              |



### 🦉重要的回溯模版

#### 排列回溯

```c++
/**
 * 本题来自于洛谷模板题 P1706
*/
int n, x[MAXN], vis[MAXN], path[MAXN];
void dfs(int plen){
    if(plen == n){
        // Do something here...打印结果或是进行其它操作...
        return;
    }
    for (int i = 0; i < n; i++){
        if(!vis[i]){
            vis[i] = 1, path[plen] = x[i];
            dfs(plen + 1);
            vis[i] = 0, path[plen] = 0;
        }
    }
}
```



#### 组合回溯

```c++
/**
 * 本题来自于洛谷模板题 P1157
*/
int n, r, x[MAXN], vis[MAXN], path[MAXN];
void dfs(int start, int plen){
    if(plen == r){
        // Do something here...打印结果或是进行其它操作...
        return;
    }
    for (int i = start; i < n; i++){
        if(!vis[i]){
            vis[i] = 1, path[plen] = x[i];
            dfs(i + 1, plen + 1);
            vis[i] = 0, path[plen] = 0;
        }
    }
}
```

