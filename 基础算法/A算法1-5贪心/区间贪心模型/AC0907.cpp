#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 100005
typedef struct range{
    int lo, hi;
    const bool operator < (const struct range &other) const{
        return lo < other.lo;
    }
}Range;

Range ranges[MAXN];

int bg, ed, n, a, b;
int main(){
    scanf("%d %d", &bg, &ed);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        ranges[i] = {a, b};
    }
    sort(ranges, ranges + n);
    
    int ans = 0;
    bool success = false;
    for(int i = 0; i < n; i++){
        int j = i, rt = -2e9;
        while(j < n  && ranges[j].lo <= bg){
            rt = max(rt, ranges[j].hi);
            j++;
        }
        if(rt < bg)
            break;
        ans++;
        if(rt >= ed){
            success = true;
            break;
        }
        bg = rt;    // 随后子问题变成了如何覆盖 [rt, ed]
        i = j - 1;  // i跳到 j，但是因为for循环会进行自增操作，跳到 j - 1 即可
    }
    printf("%d\n", success ? ans : -1);
    return 0;
}