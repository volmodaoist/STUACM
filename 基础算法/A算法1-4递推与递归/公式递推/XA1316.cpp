#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

typedef long long ill;
typedef unsigned long long ull;
#define  MAXN  3000

/**
 * @brief 
 * 使用下面这种方法获取位数的方法会超时
 */
ull getBits(ull x){
    ull bits = 0;
    while(x){
        x /= 10;
        bits += 1;
    }
    return bits;
}

/**
 * @brief 
 * 改用sizeTable方法效率大概提高了五倍,
 * 然而最后一个样例仍然超时,推测是因为prefix导致n爆掉超出int范围
 */
ull sizeTable[10] = {
    9, 99, 999, 9999, 99999, 999999, 9999999,99999999, 999999999, INT_MAX
};

int getBitsBySizeTable(int x){
    for (int i = 0; ; i++){
        if(x <= sizeTable[i]){
            return i + 1;
        }
    }
}

/**
 * 然而并没有必要计算 i * bits + n, 所以位数取出也是不必要的,
 * 因而下面的超时代码可以去掉 i * bits + n 部分
 */
ull solve_TE(ull n, ull prefix){
    ull ans = 1, half = prefix / 2;
    if (half == 0)
        return 1;
    int bits = getBits(n);
    for (int i = 1; i <= half; i++){
        ans += solve_TE(i * bits + n, i);
    }
    return ans;
}

ull n, memo[MAXN] = {1};

ull solve(ull prefix){
    ull ans = 1, half = prefix / 2;
    if (memo[prefix] != 0)
        return memo[prefix];
    for (int i = 1; i <= half; i++){
        ans += solve(i);
    }
    memo[prefix] = ans;
    return memo[prefix];
}

int main(){ 
    while (cin >> n){
        cout << solve(n) << endl;
    }

    return 0;
}