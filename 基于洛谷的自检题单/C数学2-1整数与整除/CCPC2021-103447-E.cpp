#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
 
 
typedef long long llong;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
#define  MAXN  100005
 

// https://codeforces.com/gym/103447/problem/E
int n, kase, a[MAXN];
int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif
 
    scanf("%d", &kase);
    while(kase--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
 
        int m = 0;
        bool maybe_ok = false;
 
        // 观察数据范围可知，必然会出现某一个下标i使得 a[i]不等于bi，我们先找第一个不满足的式子
        for (int i = 1, bi = 1; i <= n; i++) {
            bi = (1 << (i - 1));
            if(a[i] < bi){
                maybe_ok = true;
                m = bi - a[i];
                break;
            } else if (a[i] > bi) {
                maybe_ok = false;
                break;
            }
        }

        // 其中 2^(i-1) = bi，找到第一个小于 bi 元素，猜个模数然后验证是否符合即可
        if(maybe_ok){
            for (int i = 2; i <= n; i++) {
                if (a[i] != a[i - 1] * 2 % m){
                    maybe_ok = false;
                    break;
                }
            }
        }
 
        cout << (maybe_ok ? m : -1) << endl;
    }
    return 0;
}