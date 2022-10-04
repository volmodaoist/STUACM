#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	CLEAR(A,x)  (memset(A,x,sizeof(A)))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long llong;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  fi    first
#define  se    second
#define  MAXN  100005

int s[MAXN], n = 0;
int main() {
    // 使用增量构造法，默认初始状态存入一个空集

    while(cin>>s[n]) n++;
    vector<llong> inc(1, 0);
    
    // 增量构造的过程有点类似于宽度优先搜索
    for (int i = 0; i < n; i++) {
        int len = inc.size();
        for (int j = 0; j < len; j++){
            inc.push_back(inc[j] + s[i]);
        }
    }
    // 然而如果给定集合较大，这种做法时间与空间都无法承受
    llong ans = 0;
    for (int i = 0; i < inc.size(); i++) {
        ans += inc[i];
    }
    cout << ans << endl;
    return 0;
}
