### 📚本章纲要

- 递归与递推
  - 线性结构递归序列
    - 前序遍历
    - 后序遍历

  - 待定系数法速推递推式
- 二进制相关的计算底层原理

  - 位运算技巧
  - 二进制枚举
  - 二进制拆分
- 命题逻辑







###  🔮位运算技巧汇总

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

x &= x - 1; // 最低位 1 变成 0
x |= x + 1; // 最低位 0 变成 1

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

```c++
// 使用位运算实现加减法，编译器未必支持负数的移位运算，因而转为无符号整数会更保险一些
int add_sub(int a, int b) {
  while(b){
    int t = a ^ b;
    b = (unsigned int)(a & b) << 1;
    a = t;
  }
  return a;
}
```

```c++
// 使用加减法与位运算实现除法，
```

