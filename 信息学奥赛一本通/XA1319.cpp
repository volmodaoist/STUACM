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


int n, x;
typedef struct Node{
	int id;
	int tc;
} Node;

Node nodeList[1050];

int main(){    
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    #ifndef  _OJ_ONLINE_JUDGE_
    std::ios::sync_with_stdio(false);
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);//
    #endif

    while(cin >> n){
        for (int i = 1; i <= n; i++){
            // cin >> x;
            // nodeList[i].tc = x;
            // nodeList[i].id = i;
            // 遇到了一个很神奇的问题,为什么注释部分的代码WA,明明逻辑跟下面是一样的
            // nodeList[i].id = i;
            // cin >> nodeList[i].tc;
        }

        sort(nodeList + 1, nodeList + n + 1, [](const Node &a, const Node &b){
            if(a.tc == b.tc){
                return a.id < b.id;
            }
            return a.tc < b.tc;
        });

        double ans = 0;
        for (int i = 1; i <= n; i++){
            ans += nodeList[i].tc * (n - i);
        }
        ans /= n;
        for (int i = 1; i <= n; i++){
            cout << nodeList[i].id << (i != n ? " " : "\n");
        }
        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}