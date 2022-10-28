#include <bits/stdc++.h>
#include <iomanip>
using namespace std;


typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  xx    first
#define  yy    second
#define MAXN   5000


int factor(int u, int x){
    int ans = 1;
    for (int i = u; i * i <= x; i++){
        if (x % i == 0){
            ans += factor(i, x / i);
        }
    }

    return ans;
}

int kase, x;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif

    cin >> kase;
    while(kase--){
        cin >> x;
        cout << factor(2, x) << endl;
    }
    return 0;
}