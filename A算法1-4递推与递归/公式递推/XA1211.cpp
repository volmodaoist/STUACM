#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

bool judge(int x, int k){
    if(x < k)
        return false;
    if (x == k)
        return true;
    return judge(x, 2 * k + 1) | judge(x, 3 * k + 1);
}


int kase, x, k;
int main(){ 
    while(scanf("%d,%d", &k, &x)!=EOF){

        cout << (judge(x, k) ? "YES" : "NO") << endl;
    }
    return 0;
}