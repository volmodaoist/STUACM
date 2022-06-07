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
#define  MAXN  2000


char path[MAXN];
void dfs(string& ss, int u, int state){
    if(u == ss.size()){
        for (int i = 0; i < ss.size(); i++){
            cout << path[i];
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < ss.size(); i++){
        if (!(state & (1 << i))){
            path[u] = ss[i];
            dfs(ss, u + 1, state | (1 << i));
        }
    }
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

    string ss;
    while (cin >> ss){
        dfs(ss, 0, 0);
    }

    return 0;
}
