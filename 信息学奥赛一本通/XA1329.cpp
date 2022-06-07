#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	min4(x,y,u,v)	(min(min(x,y),min(u,v)))
#define	max4(x,y,u,v)	(max(max(x,y),max(u,v)))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  inserter(x, x.begin())
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <iomanip>
using namespace std;


typedef long long Long;
typedef unsigned long long ULL;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii>  vii;
#define  xx    first
#define  yy    second

int dx[4] = {1, 0, -1,  0};
int dy[4] = {0, 1,  0, -1};

void dfs(vector<vector<int>> &mat, int x, int y){
    mat[x][y] = 0;
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < mat.size() && ny >= 0 && ny < mat[0].size() && mat[nx][ny] != 0){
            dfs(mat, nx, ny);
        }
    }
}

int n, m, kase;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    #ifndef  _OJ_ONLINE_JUDGE_
    std::ios::sync_with_stdio(false);
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);//
    #endif

    while (scanf("%d %d", &n, &m) != EOF){
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                scanf("%1d", &mat[i][j]);
                // printf("%1d", mat[i][j]);
            }
            // printf("\n");
        }
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if(mat[i][j] > 0){
                    ans++;
                    dfs(mat, i, j);
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}