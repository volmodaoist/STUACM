#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int path[105];
int n, org, cnt;

int dfs(int u ,int n){
    if(n <= 0 && u > 2){
        // 因为 u = 1 会有 10 = 10 这种平凡分解
        bool first = true;
        cout << org << "=";
        for (int i = 1; i < u; i++){
            cout << (first ? string() : string("+")) << path[i];
            first = false;
        }
        cout << endl;
        return 1;
    }
    int ret = 0;
    for (int i = 1; i <= n; i++){
        if (path[u - 1] <= i){
            path[u] = i;
            ret += dfs(u + 1, n - i);
        }
    }
    return ret;
}


int main(){ 
    while (cin >> n){
        org = n;
        cnt = dfs(1, n);
    }
    return 0;
}