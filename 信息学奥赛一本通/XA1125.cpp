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

#define MAXN 1005
int mat1[MAXN][MAXN];
int mat2[MAXN][MAXN];
int mat3[MAXN][MAXN];

void readMat(int m, int n, int mat[][MAXN]){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> mat[i][j];
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

void mulMat(int n, int m, int k, int mat1[][MAXN], int mat2[][MAXN]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            for (int z = 0; z < m; z++){
                mat3[i][j] += (mat1[i][z] * mat2[z][j]);
            }
        }
    }
}

int m, n, k;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    #ifndef  _OJ_ONLINE_JUDGE_
    std::ios::sync_with_stdio(false);
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);//
    #endif

    while (cin >> n >> m >> k){
        memset(mat1, 0, sizeof(mat1));
        memset(mat2, 0, sizeof(mat2));
        memset(mat3, 0, sizeof(mat3));
        
        readMat(n, m, mat1);
        // printMat(n, m, mat1);
        
        readMat(m, k, mat2);
        // printMat(m, k, mat2);

        mulMat(n, m, k, mat1, mat2);
        printMat(n, k, mat3);
    }
    return 0;
}