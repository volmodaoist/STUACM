#include <iostream>
#include <cstring>

using namespace std;

const int N = 20010;

int dp[N], prec[N], q[N];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        memcpy(prec, dp, sizeof(dp));
        int v, w, s;
        cin >> v >> w >> s;
        
        /**
         * 根据同余关系进行分组 dp[m] 能从 dp[m - kv] 转移而来，随着 k 增加，m - kv 减少到某个余项
         * dp[0], dp[0 + v], dp[0 + 2v], dp[0 + 3v], ... dp[0 + kv],
         * dp[1], dp[1 + v], dp[1 + 2v], dp[1 + 3v], ... dp[1 + kv],
         *  ...
         * dp[j], dp[j + v], dp[j + 2v], dp[j + 3v], ... dp[j + kv],
        */ 
        for(int j = 0; j < v; j++){
            int head = 0, tail = -1;
            for(int k = j; k <= m; k += v){
                if(head <= tail && k - q[head] > s * v){
                    head++;
                }
                // 其中进入单调队列的其实是一个索引，这个索引对应 dp[j - kv] - kw
                while(head <= tail && prec[q[tail]] - (q[tail] - j) / v * w <= prec[k] - (k - j) / v * w){ // 减掉余项进行比较
                    tail--;
                }
                if(head <= tail) dp[k] = max(dp[k], prec[q[head]] + (k - q[head]) / v * w);
                q[++tail] = k;
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}
