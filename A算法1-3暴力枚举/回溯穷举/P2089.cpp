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
#define  MAXN  100005


// 回溯算法
int n, path[10], vis[10], ans[MAXN][10], cnt;
void dfs(int total, int x) {
    if (x == 10 || total >= n) {
        // 此处的写法是一个 trick，主要目标是为了剪枝去掉 total > n 情况
        if (x == 10 && total == n) {
            for (int i = 0; i < 10; i++){
                ans[cnt][i] = path[i];
            }
            cnt++;
        }
        return;
    }
    for (int i = 1; i <= 3; i++){
        if(!path[x]){
            path[x] = i;
            dfs(total + i, x + 1);
            path[x] = 0;
        }
    }
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d", &n);
    if (n < 10 || n > 30) {
        printf("0\n");
    } else {
        dfs(0, 0);
        printf("%d\n", cnt);
        for (int i = 0; i < cnt; i++){
            for (int j = 0; j < 10; j++){
                printf("%d ", ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}