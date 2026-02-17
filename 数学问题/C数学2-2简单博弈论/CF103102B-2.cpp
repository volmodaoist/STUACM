#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
#define  MAXN  1000005


char str[MAXN];

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    // 由于输入只有0与1 计算逆序对的方法其实可以简化
    while (scanf("%s", str) != EOF) {
        int n = strlen(str);
        ill ones = 0, rp = 0;
        for (int i = 0; i < n; i++) {
            if(str[i] == '1'){
                ones++;
            }else{
                rp += ones;
            }
        }
        cout << (rp % 3 ? "Alice" : "Bob") << endl;
    }
    return 0;
}