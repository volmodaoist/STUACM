#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	min4(x,y,u,v)	(min(min(x,y),min(u,v)))
#define	max4(x,y,u,v)	(max(max(x,y),max(u,v)))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  inserter(x, x.begin())
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <iomanip>
using namespace std;


typedef long long Long;
typedef unsigned long long ULL;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii>  vii;
#define  xx    first
#define  yy    second
#define  MAXN  3000

/**
 * @brief 
 * 使用下面这种方法获取位数的方法会超时
 */
ULL getBits(ULL x){
    ULL bits = 0;
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
int sizeTable[10] = {
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
 * @brief 
 * 然而并没有必要计算 i * bits + n, 所以位数取出也是不必要的,
 * 因而下面的超时代码可以去掉 i * bits + n 部分
 */
ULL solve_TE(ULL n, ULL prefix){
    ULL ans = 1, half = prefix / 2;
    if (half == 0)
        return 1;
    int bits = getBits(n);
    for (int i = 1; i <= half; i++){
        ans += solve_TE(i * bits + n, i);
    }
    return ans;
}

ULL memo[MAXN] = {1};
ULL solve(ULL prefix){
    ULL ans = 1, half = prefix / 2;
    if (memo[prefix] != 0)
        return memo[prefix];
    for (int i = 1; i <= half; i++){
        ans += solve(i);
    }
    memo[prefix] = ans;
    return memo[prefix];
}

int kase;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    #ifndef  _OJ_ONLINE_JUDGE_
    std::ios::sync_with_stdio(false);
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);//
    #endif

    ULL n;
    while (cin >> n){
        cout << solve(n) << endl;
    }

    return 0;
}