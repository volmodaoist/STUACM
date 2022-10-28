#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

int main(){ 
    int n, x, y, z, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x, &y, &z);
        if (x + y + z >= 2){
            ans ++;
        }
    }
    printf("%d\n", ans);
    return 0;
}