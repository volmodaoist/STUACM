### 🌹本章纲要

- 子串匹配 

  - Rabin-Karp 算法 (前置知识：对字符串哈希)

  - Kruth-Morris-Pratt 算法 (前置知识：循环同构串的最小表示法)

    - 循环同构字符串最小表示法

    - 利用信息跳转信息计算字符串循环节

    - 使用 Z 函数 计算最长公共前缀 LCP

  - Trie 单词查找树
  - Manacher 算法





### 🌴 单词查找树 (aka 字典树 Trie)

单词查找树虽然最开始发明出来是用于解决单词搜索问题，但其另外一个广泛的用途便是解决异或类型问题

|          题目          |                思路描述                |
| :--------------------: | :------------------------------------: |
|   AC0143. 最大异或对   | 使用 Trie 走相反零一方向求解最大异或值 |
|  AC4507. 子数组异或和  |                                        |
|  AC03485. 最大异或和   |                                        |
| AC0144. 最长异或值路径 |                                        |
|   LG4735. 最大异或和   |             可持久化字典树             |





### 🦉处理字符串套路模板

#### 对字符串分割

```c++
/** 
 * Python 语言的写法 str.split('/')，通过 c++STL  getline 能够实现等价的写法，
 * 内置的 STL 其实能够处理很多乱七八糟的字符串读入问题，例如按照某个字符把串分段的函数，
 * 函数 getline 不仅适用于 cin 而且能用 istringstream 对象来对一般字符串进行这种分割操作！
*/

string str;
getline(cin, str, '/');

istringstream iss(str);
while(getline(iss, str, '/')){
  	cout << str << endl;
}
```





#### 对字符串哈希

```c++
ull H[MAXN], T[MAXN], n , p = 13331, len;
ull hash_in(char s[]) {
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
      	P[i] = P[i - 1] * p;
        H[i] = H[i - 1] * p + s[i];
    }
    return H[n];
}

ull get_hash(int L, int R){
  	return H[R] - H[L - 1] * P[R - L + 1];
}

bool substr(int L1, int R1, int L2, int R2){
  	return get_hash(L1, R1) == get_hash(L2, R2);
}
```



### ⚔️ 处理字符串例题选讲

|       题目       |                    思路描述                     |
| :--------------: | :---------------------------------------------: |
| LC0071. 简化路径 | 使用 istringstream 与getline 分割字符串的模板题 |
|                  |                                                 |
|                  |                                                 |