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
#define  MAXN  1005

int mat[MAXN][MAXN];
int rowm[MAXN], colm[MAXN];

// 本题来自于 2021CCPC哈尔滨站 第J题，Local Minimum，这是一道签到题，
// 要求找出矩阵中等于行最小值且等于列最小的元素个数

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    for (int i = 0; i < n; ++i){
        rowm[i] = mat[i][0];
        for (int j = 1; j < m; j++){
            rowm[i] = min(rowm[i], mat[i][j]);
        }
    }

    for (int j = 0; j < m; ++j) {
        colm[j] = mat[0][j];
        for (int i = 1; i < n; i++){
            colm[j] = min(colm[j], mat[i][j]);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            if(mat[i][j] == rowm[i] && mat[i][j] == colm[j]){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}