#include<bits/stdc++.h>
using namespace std;

typedef long long ill;

ill n, m, primes[30];
int main(){
    scanf("%lld %lld", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%lld", &primes[i]);
    }
    // 枚举所有可能的集合
    ill ans = 0;
    for(int i = 1; i < (1 << m); i++){
        ill s = 0, prod = 1; 
        for(int j = 0; j < m; j++){
            if(i >> j & 1){
                s++;
                prod = prod * primes[j];
                if(prod > n){
                    prod = -1; //及时跳出否则有可能会爆掉ill
                    break;
                }
            }
        }
        if(prod == -1) continue;
        ans += (n / prod) * (s & 1 ? 1 : -1);
    }
    printf("%lld\n", ans);
    return 0; 
}