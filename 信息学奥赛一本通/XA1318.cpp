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

int path[105], org, cnt;
int dfs(int u ,int n){
    if(n <= 0 && u > 2){
        // 因为 u = 1 会有 10 = 10 这种平凡分解
        bool first = true;
        cout << org << "=";
        for (int i = 1; i < u; i++){
            cout << (first ? string() : string("+")) << path[i];
            first = false;
        }
        cout << endl;
        return 1;
    }
    int ret = 0;
    for (int i = 1; i <= n; i++){
        if (path[u - 1] <= i){
            path[u] = i;
            ret += dfs(u + 1, n - i);
        }
    }
    return ret;
}


int kase;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    #ifndef  _OJ_ONLINE_JUDGE_
    std::ios::sync_with_stdio(false);
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);//
    #endif

    int n;
    while (cin >> n){
        org = n;
        cnt = dfs(1, n);
        // cout << "total=" << cnt << endl;
    }

    return 0;
}