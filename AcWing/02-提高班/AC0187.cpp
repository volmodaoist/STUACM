#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 55
int n;
int h[MAXN], up[MAXN], down[MAXN];

// 这种深搜但凡有一个返回 true 其返回值便是 true
bool dfs(int depth, int u, int su, int sd){
    if(su + sd > depth) 
        return false;
    if(u == n)
        return true;
    
    bool in_inc_seq = false;
    for(int i = 1; i <= su; i++){
        if(up[i] < h[u]){
            int  t = up[i];
            up[i] = h[u];
            if(dfs(depth, u + 1, su, sd)) return true;
            up[i] = t;
            in_inc_seq = true; //这句话移到if语句之前也行
            break;
        }
    }
    if(!in_inc_seq){ // 如果无法放进任何一个上升序列里面则应新开一个上升序列
        up[su + 1] = h[u];
        if(dfs(depth, u + 1, su + 1, sd)) return true;
    }
    
    bool in_dec_seq = false; 
    for(int i = 1; i <= sd; i++){
        if(down[i] > h[u]){
            int  t = down[i];
            down[i] = h[u];
            if(dfs(depth, u + 1, su, sd)) return true;
            down[i] = t;
            in_dec_seq = true; //这句话移到if语句之前也行
            break;
        }
    }
    if(!in_dec_seq){ // 如果无法放进任何一个下降序列里面则应新开一个下降序列
        down[sd + 1] = h[u];
        if(dfs(depth, u + 1, su, sd + 1)) return true;
    }
    return false;
}

int main(){
    while(cin >> n && n){
        for(int i = 0; i < n; i++){
            cin >> h[i];
        }
        int depth = 0;
        while(!dfs(depth, 0, 0, 0)) 
            depth++;
        cout << depth << endl;
    }
}