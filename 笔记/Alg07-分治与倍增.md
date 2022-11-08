### 📘本章纲要

- 朴素的分治思路是如何解决问题的？
- 进阶的分治思想是如何解决问题的？

  - 根号级复杂度的分治
    - SRD 分治思想[^SRD]
    - 莫队算法
  - 对数级复杂度的分治
    - CDQ 分治思想[^CDQ]
    - 维护区间的树家族
      - 树状数组
      - 线段树家族
      - 平衡树家族
    - 树分治算法
      - 静态：点分治 + 边分治
      - 动态：点分树
    - 分治搜索
      - 二分搜索 (答案区间已知的最值极化[^最值极化]问题)
      - 三分搜索 (单峰连续二元函数矩形区域极值求解)


- 倍增思想能够帮助我们解决什么问题？
  - 线性结构的 **区间最值查询问题 (RMQ)**
  - 树形结构的 **最近公共祖先问题 (LCA)**





### ⚔️分治例题精选

|                     题目                     |      思路描述      |
| :------------------------------------------: | :----------------: |
|          LG1257. 平面上最接近的点对          |                    |
|               LG1228. 地毯填补               |     分治模拟题     |
|            LC240. 搜索二维矩阵 II            | 二维「之字形」搜索 |
| NC16534. 积木大赛<br/>NC21466. 道路铺设<br/> |  分治找最值的变体  |



### ⚔️分治查找例题精选

|                             题目                             |                          描述                          |
| :----------------------------------------------------------: | :----------------------------------------------------: |
| LC2439. 最小化数组的最大值<br/>LC0875. 爱吃香蕉的珂珂<br/>LC1482. 制作 m 束花所需的最少天数<br/>LCP0012. 小张刷题计划<br/> |     均为二分猜答案问题，通常会出现最值极化的关键词     |
|                 LC2448. 使数组相等的最小开销                 | 会发现曲线是一个开口向上的抛物线，故以三分搜索找最优值 |
|                                                              |                                                        |





### 🦉分块思想代码实现

#### 分块查询区间和

```c++
int n, a, b, c, op;
int seq[MAXN], atg[MAXN], sumv[MAXN], pos[MAXN], L[MAXN], R[MAXN];

// 分块过程, 使用1-base下标, 然后注意最后一块的右边界不可以超过数组的最大长度
void build(){
    int t = sqrt(n * 1.0);
    int blocks = n / t + (n % t != 0);
    for (int i = 1; i <= blocks; i++){
        L[i] = (i - 1) * t + 1;
        R[i] = i * t;
    }
    R[blocks] = n;
    for (int i = 1; i <= blocks; i++){
        for (int j = L[i]; j <= R[i]; j++){
            pos[j] = i;
            sumv[i] += seq[j];
        }
    }
}

void update(int lo, int hi, int c){
    int p = pos[lo], q = pos[hi];
    if (p == q){
        for (int i = lo; i <= hi; i++){
            seq[i] += c;
        }
        sumv[p] += ((hi - lo + 1) * c);
    }else{
        for (int i = p + 1; i <= q - 1; i++){
            atg[i] += c;
        }
        for (int i = lo; i <= R[p]; i++){ seq[i] += c;} // 左端暴力修改
        sumv[p] += ((R[p] - lo + 1) * c);
        for (int i = L[q]; i <= hi; i++){ seq[i] += c;} // 右端暴力修改
        sumv[q] += ((hi - L[q] + 1) * c);
    }
}

int query(int lo, int hi){
    int p = pos[lo], q = pos[hi], ans = 0;
    if (p == q) {
        for (int i = lo; i <= hi; i++){
            ans += seq[i];
        }
        ans += (atg[p] * (hi - lo + 1));
    } else {
        for (int i = p + 1; i <= q - 1; i++) {
            ans += sumv[i] + atg[i] * (R[i] - L[i] + 1);
        }
        for (int i = lo; i <= R[p]; i++){
            ans += seq[i];
        }
        ans += (atg[p] * (R[p] - lo + 1));
        for (int i = L[q]; i <= hi; i++){
            ans += seq[i];
        }
        ans += (atg[q] * (hi - L[q] + 1));
    }
    return ans;
}
```



#### 分块排序查询较小值个数

```c++
int a, b, c, n, op;
int seq[MAXN], pos[MAXN], atg[MAXN], L[MAXN], R[MAXN];
vector<int> v[MAXN];

void build(){
    int t = sqrt(n * 1.0);
    int blocks = (n / t) + (n % t != 0);
    for (int i = 1; i <= blocks; i++) {
        L[i] = (i - 1) * t + 1;
        R[i] = i * t;
    }
    R[blocks] = n;
    for (int i = 1; i <= blocks; i++){
        for (int j = L[i]; j <= R[i]; j++){
            pos[j] = i;
            v[i].push_back(seq[j]);
        }
        sort(v[i].begin(), v[i].end());
    }
}

void reset(int x){
    v[x].clear();
    for (int i = L[x]; i <= R[x]; i++){
        v[x].push_back(seq[i]);
    }
    sort(v[x].begin(), v[x].end());
}

void update(int lo, int hi, ill c){
    int p = pos[lo], q = pos[hi];
    if (p == q){
        for (int i = lo; i <= hi; i++){
            seq[i] += c;
        }
        reset(p);
    }else{
        for (int i = lo; i <= R[p]; i++){ seq[i] += c;} reset(p); // 左端暴力修改
        for (int i = L[q]; i <= hi; i++){ seq[i] += c;} reset(q); // 右端暴力修改
        for (int i = p + 1; i <= q - 1; i++){
            atg[i] += c;
        }
    }
}

ill query(int lo, int hi, ill c){
    ill ans = 0;
    int p = pos[lo], q = pos[hi];
    if (p == q) {
        for (int i = lo; i <= hi; i++){
            if(seq[i] + atg[p] < c){
                ans++;
            }
        }
    }else{
        for (int i = lo; i <= R[p]; i++){ if(seq[i] + atg[p] < c) ans++; } // 左端对答案的贡献
        for (int i = L[q]; i <= hi; i++){ if(seq[i] + atg[q] < c) ans++; } // 右端对答案的贡献
        for (int i = p + 1; i <= q - 1; i++){
            ans += (lower_bound(v[i].begin(), v[i].end(), c - atg[i]) - v[i].begin());
        }
    }
    return ans;
}
```





### 本文批注

[^SRD]: SRD 分治思想是一个英文缩写，Sqrt Root Decomposition，或称 Sqrt Decomposition，因而缩写亦为 SD。
[^CDQ]: CDQ 分治的思想最早由 IOI2008 金牌得主陈丹琦在高中时整理并总结，故此得名。
[^最值极化]: 最大值极小化与最小值极大化，或者也称最大值最小化与最小值最大化，二者简称最值极化问题。