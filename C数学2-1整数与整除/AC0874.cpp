#include<bits/stdc++.h>
using namespace std;

typedef long long LLong;

#define MAXN 1000005

bool excl[MAXN]; 
LLong phi[MAXN], prime[MAXN], cnt;


LLong euler(int n){
    phi[1] = 1;
    for(int i = 2; i <= n; i++){
        if(!excl[i]){
            prime[cnt++] = i;
            phi[i] = i - 1;
        }
        for(int j  = 0; prime[j] <= n/i; j++){
            excl[i * prime[j]] = true;
            if(i % prime[j] == 0){
                phi[i * prime[j]] =  phi[i] * prime[j];    
                break;
            }
            phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
    LLong ans = 0;
    for(int i = 1; i <= n; i++){
        ans += phi[i];
    }
    return ans;
}

int n, x;
int main(){
    scanf("%d", &n);
    printf("%lld\n", euler(n));
    return 0;
}