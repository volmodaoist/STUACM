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


int mat[MAXN][MAXN];
int tam[MAXN][MAXN];

void readMat(int m, int n, int mat[][MAXN]){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }
}

void rotatMat(int m, int n, int mat[][MAXN]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            tam[i][j] = mat[j][i];
        }
    }
    for (int i = 0; i < n; i++){
        int lo = 0, hi = m - 1;
        while(lo <= hi){
            swap(tam[i][lo], tam[i][hi]);
            lo++, hi--;
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



int m, n;
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
        readMat(m, n, mat);
        rotatMat(m, n, mat);

        printMat(n, m, tam);
    }
    return 0;
}