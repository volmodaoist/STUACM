#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

// https://codeforces.com/contest/1343/problem/B
int kase, n;
int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d", &kase);
    while(kase--){
        scanf("%d", &n);
        if (n % 4 == 0){
            printf("YES\n");
            vector<int> ans;
            for (int i = 2; i <= n; i += 2) {
                ans.push_back(i);
            }
            for (int i = 1; i <= n; i += 2){
                ans.push_back(i);
            }
            ans[ans.size() - 1] += n / 2;
            for (int i = 0; i < ans.size(); i++){
                printf("%d ", ans[i]);
            }
            printf("\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}