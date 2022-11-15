#include <bits/stdc++.h>
#include <limits>
using namespace std;


#define  MAXN  105

int n, a, b;
bool g[MAXN][MAXN];
void floyd(){
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                g[i][j] |= (g[i][k] && g[k][j]);
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++){
        scanf("%d %d", &a, &b);
        g[a][b] = true;
    }
    floyd();
    for (int i = 1; i <= n; i++){
        int t = 0;
        for (int j = 1; j <= n; j++) {
            if(g[j][i]){
                t++;
            }
        }
        if(t == n){
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}