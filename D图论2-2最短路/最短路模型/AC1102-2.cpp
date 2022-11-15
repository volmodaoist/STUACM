#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

// 移动轨迹向量化
int add[3] = {+1, -1,  0};
int mul[3] = { 0,  0,  1};
int vist[100005];
int n, k, N = 1e5;

int bfs(){
    if(n >= k){
        return n - k;
    }
    queue<ii> q; q.push({n, 0});
    while(q.size()){
        auto [x, s] = q.front();q.pop();
        for(int i = 0; i < 3; i++){
            int nx = add[i] + mul[i] * x + x;
            if(nx < 0 || nx > N  || vist[nx]){
                continue;
            }
            vist[nx] = 1;
            q.push({nx, s + 1});
            if(nx == k){
                return s + 1;
            }
        }
    }
    return 0;
}

int main(){
    scanf("%d %d", &n, &k);
    printf("%d\n", bfs());
    return 0;
}