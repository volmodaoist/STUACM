#include<bits/stdc++.h>
using namespace std;

typedef long long LLong;
unordered_map<int,int> hash_in;
 
int n, x;
int MOD = 1e9 + 7;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        for(int j = 2; j <= x / j; j++){
            while(x % j == 0){
                x = x / j;
                hash_in[j]++;
            }
        }
        if(x > 1) hash_in[x]++;
    }

    // 重点在于这里的多项式相乘算法，非常巧妙
    
    LLong ans = 1;
    for(auto &kv: hash_in){
        LLong p = kv.first, a = kv.second, t = 1;
        while(a--){
            t = (t * p + 1) % MOD;
        }
        ans = ans * t % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}