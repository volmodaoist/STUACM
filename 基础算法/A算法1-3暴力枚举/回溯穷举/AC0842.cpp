#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
int path[MAXN], vist[MAXN];

void dfs(int u, int n){
    if(u > n){
        for(int i = 1; i <= n; i++){
            cout << path[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!vist[i]){
            path[u] = i;
            vist[i] = 1;
            dfs(u + 1, n);          
            vist[i] = 0;
        }
    }
}

int n;
int main(){
    while(cin >> n){
        dfs(1, n);
    }
    return 0;
}