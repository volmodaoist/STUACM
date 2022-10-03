

###  基本位运算操作

```c++
// 开启集合的第j位元素的状态， To turn on j-th item  of the set
S |= (1<<j);

// 关闭集合的第j位元素的状态， To turn off the j-th item of the set
S &= ~(1<<j);

// 检查集合S第j位元素的状态，To check if the j-th item of the set is on
T = S & (1<<j);

// 翻转集合的第j位元素的状态，To toggle the status of the j-th item of the set
S ^= (1<<j);

// 激活一个n元素激活集合所有位, To turn on all bits in a set of size n by Shift
S = (1 << n) - 1;

// 获取末尾1， To get the lowest bit-wise 1 in Integer
#define lowbit(x)  ((x)&(-x))

// 枚举所有子集, To enumerate all proper subsets of a given a bitmask
int mask = GivenMask;
for(int s = mask; s; s = (mask & s - 1)){
    cout<< subset <<endl;
}

// 在整数中按位枚举所有1(方法1), Enumerate all bit-wise 1 in Integer (Method 1)
for(int i = 0; i < (1<<n) ;++i){
    for(int j = 0; j<n; ++j){
        if(i & (1<<j)){
          ...
        }
    }
}

// 在整数中按位枚举所有1(方法2),  Enumerate all bit-wise 1 in Integer (Method 2)
for(int i = 0; i<(1<<n); ++i){
    int t = i;
    while(t){
      	int x = lowbit(x);
        int j = __builtin_ctz(x);
        t -= x;
    }
}

// 快速判断一个数n是否满足 n = 2^k
bool is_pow2k  = ((n & (n - 1)) == 0);
```





### 关于STL工具的奇技淫巧

```c++
//枚举排列组合,复杂度O(n!)
next_permutation(a,a+n);
prev_premutation(a,a+n);

#define ALL(c) (c.begin()),(c.end())

// 对于容器的所有元素执行某个函数
for_each(ALL(container), func);

// 向量容器转为堆容器
make_heap(ALL(vec));
push_heap(ALL(vec)) + pop_heap(ALL(vec));
sort_heap(ALL(vec));
```



### 检查有序性

```c++
is_sorted(ALL(container));
is_sorted_until(ALL(container));

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a[5] = { 1,3,4,2,5 };
	cout <<  is_sorted_until(a, a + 5) << endl;
	cout << *is_sorted_until(a, a + 5) << endl;
    // 返回第一个破坏有序性的元素 2
}
```



### 获取最值的索引

```c++
max_element(a, a + 5);
min_element(a, a + 5);

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a[5] = {1, 3, 4, 2, 5};
	cout << max_element(a, a + 5) << *max_element(a, a + 5) << endl;
	cout << min_element(a, a + 5) << *min_element(a, a + 5) << endl;
}
```



### 负索引迭代器

```cpp
#include<vector>
#include<iostream>
using namespace std;
int main(){
    vector <int> v = {1, 2, 3, 4, 5};
	cout << v.end()[-1] << endl;
}
```





### 常用的魔法数字

| 魔法数字  |                         用途                          |
| :-------: | :---------------------------------------------------: |
|   0x7f    |     memset(dp, 0x7f, sizeof(dp)) 初始化一个极大值     |
|   0x3f    |     memset(dp, 0x3f, sizeof(dp)) 初始化一个较大值     |
|   0xc0    |     memset(dp, 0xc0, sizeof(dp)) 初始化一个较小值     |
|   0x80    |     memset(dp, 0x80, sizeof(dp)) 初始化一个极小值     |
| 31 (32-1) | s[i] &31 相当于 s[i] - 'a' + 1，也即1-base计数字母序  |
| 63 (64-1) | s[i] & 63 相当于 s[i] - 'A' + 1，也即1-base计数字母序 |