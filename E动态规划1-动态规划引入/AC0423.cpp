#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 1005

int t, m;
int times[MAXN], value[MAXN], dp[MAXN];

int main(){
    cin >> t >> m;
    for(int i = 0; i < m; i++){
        cin >> times[i] >> value[i];
        for(int j = t; j >= times[i]; j--){
            dp[j] = max(dp[j], dp[j - times[i]] + value[i]);
        }
    }
    cout << dp[t] << endl;
    return 0;
}