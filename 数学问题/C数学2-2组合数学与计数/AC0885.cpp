#include<bits/stdc++.h>
using namespace std;

#define MAXN 2005

int MOD = 1e9 + 7;
int n, a, b, comb[MAXN][MAXN];

void solve(){
    for(int i = 0; i <= 2000; i++){
        for(int j = 0; j <= i; j++){
            if(!j){
                comb[i][j] = 1;
            }else{
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
            }
        }
    }
}


int main(){
    scanf("%d", &n);
    solve();
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", comb[a][b]);
    }
    return 0;
}