#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

char path[100005];
void dfs(string& ss, int u, int state){
    if(u == ss.size()){
        for (int i = 0; i < ss.size(); i++){
            cout << path[i];
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < ss.size(); i++){
        if (!(state & (1 << i))){
            path[u] = ss[i];
            dfs(ss, u + 1, state | (1 << i));
        }
    }
}

int main(){ 
    string ss;
    while (cin >> ss){
        dfs(ss, 0, 0);
    }

    return 0;
}
