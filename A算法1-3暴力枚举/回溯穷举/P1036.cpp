#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
#define  MAXN  100005

int n, k, x[MAXN], vis[MAXN], pick[MAXN], cnt;

bool is_prime(int x) {
    int sx = sqrt(x);
    for (int i = 2; i <= sx; i++){
        if (x % i == 0){
            return false;
        }
    }
    return true;
}

void dfs(int len, int start){
    if(len == k){
        int sumv = 0;
        for (int i = 0; i < k; i++) {
            sumv += pick[i];
        }
        // 不同的数组有可能加出同样的结果，这些都对答案有贡献，但是同一组数据的不同排列应当算作同一个结果
        if(is_prime(sumv)){
            cnt++;
            /** 
                for (int i = 0; i < k; i++){
                    printf("%d ", pick[i]);
                }
                printf("\n");
            */
        }
        return;
    }
    for (int i = start; i < n; i++){
        if(!vis[i]){
            vis[i] = 1;
            pick[len] = x[i];
            dfs(len + 1, i + 1);
            vis[i] = 0;
        }
    }
}


int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++){
        scanf("%d", &x[i]);
    }
    dfs(0, 0);
    printf("%d\n", cnt);
    return 0;
}