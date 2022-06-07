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
#define MAXN   1005



void readMat(int m, int n, int mat[][MAXN], int cpy[][MAXN]){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> mat[i][j];
            cpy[i][j] = mat[i][j];
        }
    }
}


void printMat(int m, int n, int mat[][MAXN]){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int m, n, nx, ny;
int mat1[MAXN][MAXN];
int mat2[MAXN][MAXN];
int dx[4] = {1, 0, -1,  0};
int dy[4] = {0, 1,  0, -1};

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    #ifndef  _OJ_ONLINE_JUDGE_
    std::ios::sync_with_stdio(false);
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);//
    #endif

    while (cin >> m >> n){
        readMat(m, n, mat1, mat2);
        for (int i = 1; i < m - 1; i++){
            for (int j = 1; j < n - 1; j++){
                int sum = mat1[i][j];
                for (int k = 0; k < 4; k++){
                    nx = i + dx[k];
                    ny = j + dy[k];
                    sum += mat1[nx][ny];
                }
                mat2[i][j] = round(sum / 5.0);
            }
        }
        printMat(m, n, mat2);
    }
    return 0;
}