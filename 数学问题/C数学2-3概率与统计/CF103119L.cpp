#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  MAXN  100005


// 本题来自于亚洲区域赛 https://codeforces.com/gym/103119/problem/L
// 问你随机生成一个整数序列 {ai}，每个元素都在1~n, 要求计算排列1~n数字的全排列{pi}，问你满足pi <= ai情况的期望
// 本题很容易列出式子 (n! * n!) / (n^n), 难点在于大数的处理，一种比较取巧的方法是用Python，另外一种方法是用 long double 类型



int main(){ 
    int n;
    long double ans = 1.0;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        ans = (ans * i * i) / n;
    }
    printf("%.15Lf\n", ans);

    return 0;
}