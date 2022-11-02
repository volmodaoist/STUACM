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


int vol[100];
int dp[100][3000];

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    int n, bg, ed;
    scanf("%d %d %d", &n, &bg, &ed);
    for (int i = 1; i <= n; i++){
        scanf("%d", &vol[i]);
    }

    dp[0][bg] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= ed; j++) {
            if(j - vol[i] >= 0 && dp[i - 1][j]){
                dp[i][j - vol[i]] = 1;
            }
            if (j + vol[i] <= ed && dp[i - 1][j]){
                dp[i][j + vol[i]] = 1;
            }
        }
    }

    int ans = -1;
    for(int i = ed; i >= 1; i--) {
        if(dp[n][i]){
            ans = i;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}