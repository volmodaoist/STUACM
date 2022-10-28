#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;

#define  MAXN  100005

int s[MAXN], n = 0;

// 使用增量构造法，默认初始状态存入一个空集, 
// 增量构造的过程有点类似于宽度优先搜索, 然而如果给定集合较大，这种做法时间与空间都无法承受
int main() {
    while(cin>>s[n]) n++;
    vector<ill> inc(1, 0);
    
    for (int i = 0; i < n; i++) {
        int len = inc.size();
        for (int j = 0; j < len; j++){
            inc.push_back(inc[j] + s[i]);
        }
    }

    ill ans = 0;
    for (int i = 0; i < inc.size(); i++) {
        ans += inc[i];
    }
    cout << ans << endl;
    return 0;
}
