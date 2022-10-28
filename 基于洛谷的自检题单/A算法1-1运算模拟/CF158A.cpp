#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

int main(){ 
    int n, k, s[100];
    while (scanf("%d %d", &n, &k) != EOF){
        for (int i = 1; i <= n; i++){
            scanf("%d", &s[i]);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if(s[i] >= s[k] && s[i] > 0){
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}