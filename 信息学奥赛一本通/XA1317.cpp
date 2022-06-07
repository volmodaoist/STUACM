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

int path[105];
int book[105];
void dfs(int n , int r, int u, int state){
    if (u == r + 1){
        // 这种做法其实也跟去重, 但是没办法按照字典序输出
        // book[state] = 1;
        // return;
        for (int i = 1; i <= r; i++){
            printf("%3d", path[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < n; i++){
        if (!(state & (1 << i))){
            if (i + 1 > path[u - 1]){
                path[u] = i + 1;
                dfs(n, r, u + 1, state | (1 << i));
            }
        }
    }
}


int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    #ifndef  _OJ_ONLINE_JUDGE_
    std::ios::sync_with_stdio(false);
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);//
    #endif

    int n, r;
    while (cin >> n >> r){
        memset(path, 0, sizeof(path));
        memset(book, 0, sizeof(book));
        dfs(n, r, 1, 0);

        // 这种做法其实也跟去重, 但是没办法按照字典序输出       
        // for (int state = 0; state < 105; state++){
        //     if(book[state]){
        //         for (int i = 0; i < n; i++){
        //             if((state & (1 << i))){
        //                 printf("%3d", i + 1);
        //             }
        //         }
        //         printf("\n");
        //     }
        // }
    }
    return 0;
}