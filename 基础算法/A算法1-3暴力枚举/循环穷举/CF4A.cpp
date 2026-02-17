#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


int main(){         
    /**
     * 能否分割 w，使得 w = a + b，并且 a + b 都是偶数，a 与 b 不强制要求相等，
     * 如果 a 与 b 必须相等，那么本题只需要判定 w 是不是 4 整数倍数即可，但是二者可以不相等
    */

    int w;
    scanf("%d", &w);
    bool ok = false;
    for (int i = 2; i <= w; i += 2) {
        int j = w - i;
        if (j && (~i & 1) && (~j & 1)) { 
            ok = true;
            break;
        }
        // i与j 均为偶数且不等于0
    }

    printf("%s\n", ok ? "YES" : "NO");
    return 0;
}