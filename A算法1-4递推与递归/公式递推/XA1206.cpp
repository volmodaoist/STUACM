#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  MAXN   5000


int memo[MAXN][MAXN];
int apple(int m, int n){
    if(m <= 1 || n <= 1)
        return 1;
    if (memo[m][n] != 0)
        return memo[m][n];
    if(m < n){
        return memo[m][n] = apple(m, m);
    }else{
        return memo[m][n] = apple(m - n, n) + apple(m, n - 1);
    }
}

int kase, m, n;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    #ifndef  _OJ_ONLINE_JUDGE_
    std::ios::sync_with_stdio(false);
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);//
    #endif

    cin >> kase;
    while(kase--){
        cin >> m >> n;
        cout << apple(m, n) << endl;
    }
    return 0;
}