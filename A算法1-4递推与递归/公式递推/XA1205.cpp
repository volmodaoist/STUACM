#include <bits/stdc++.h>
#include <iomanip>
using namespace std;


typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii>  vii;

/**
 * @brief
 * 想要解决汉诺塔问题要先明确起点盘、辅助盘、终点盘分布是谁，
 * 把盘子X从A移到B, 那么A起点, C辅助, B终点, 不妨假设编号 <= n - 1 那些盘子都已到C,
 * 此时n直接放在B,那么接下来C变成起点,B变为终点,A变为辅助, 这道题符合递归一贯的思想——假设“前n-1个”都已经完成!
 */
void tower(int n, char a/*src*/, char b/*dst*/, char c/*helper*/){
    if (n == 0)
        return;
    tower(n - 1, a, c, b);
    printf("%c->%d->%c\n", a, n, b);
    tower(n - 1, c, b, a);
}

int kase, n;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    #ifndef  _OJ_ONLINE_JUDGE_
    std::ios::sync_with_stdio(false);
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);//
    #endif

    char a, b, c;
    while (cin >> n >> a >> b >> c){
        tower(n, a, b, c);
    }

    return 0;
}