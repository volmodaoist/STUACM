#include<bits/stdc++.h>
using namespace std;

typedef long long llong;

int MOD = 1E9 + 7;
llong s[100005], prefix[100005];

llong quick_pow(llong a, llong b, llong p){
    llong ans = 1;
    while(b){
        if(b&1)ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}


int main(){
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    prefix[0] = 1;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &s[i]); 
        prefix[i] = prefix[i - 1] * s[i] % MOD;
    }
    while(m--){
        scanf("%d %d", &a, &b);
        
        printf("%lld\n", prefix[b] * quick_pow(prefix[a - 1], MOD - 2 , MOD) % MOD);        
    }
    return 0;
}