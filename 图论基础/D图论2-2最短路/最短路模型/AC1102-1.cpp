#include<bits/stdc++.h>
using namespace std;

typedef long long ill;
typedef struct _Node{
    ill pos, step;
}Node;

int vist[100005], N = 1e5;

int main(){
    ill n, k, ans = INT_MAX;
    scanf("%lld %lld", &n, &k);
    if(n >= k){
        ans = n - k;
    }else{
        queue<Node> q;
        q.push({n, 0});
        while(q.size()){
            auto u = q.front(); q.pop();
            if(u.pos == k){
                ans = min(ans, u.step);
                break;
            }
            if(2 * u.pos <= N && !vist[u.pos * 2]){
                q.push({u.pos * 2, u.step + 1});   
                vist[u.pos * 2] = 1;
            }
            if(u.pos  + 1 <= k && !vist[u.pos + 1]){
                q.push({u.pos + 1, u.step + 1});
                vist[u.pos + 1]  = 1;
            }
            if(u.pos - 1 >= 0 && !vist[u.pos - 1]){
                q.push({u.pos - 1, u.step + 1});  
                vist[u.pos - 1] = 1;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}