#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

typedef long long ill;
typedef unsigned long long ull;



ull bugs[105], eggs[105];
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif

    ull x, y, z;
    while (cin >> x >> y >> z){
        for (int i = 1; i <= x; i++){
            bugs[i] = 1;
            eggs[i] = 0;
        }
        for (int i = x + 1; i <= z + 1; i++){
            eggs[i] = y * bugs[i - x];
            bugs[i] = bugs[i - 1] + eggs[i - 2];
        }
        cout << bugs[z + 1] << endl;
    }

    return 0;
}