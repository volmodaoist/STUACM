#include <bits/stdc++.h>
using namespace std;
typedef long long LLong;

LLong quick_pow(LLong a, LLong b, LLong p){
    LLong ans = 1;
    while(b){
        if(b&1) ans = ans * a % p;
        a = a * a % p;
        b >>=1;
    }
    return ans;
}

LLong comb(LLong a, LLong b, LLong p){
    LLong ans = 1;
    for(int i = 1, j = a; i <= b; i++, j--){
        ans = ans * j % p;
        ans = ans * quick_pow(i, p - 2, p) % p;
    }
    return ans;
}

LLong lucas(LLong a, LLong b, LLong p){
    if(a < p && b < p)
        return comb(a,b, p);
    return comb(a%p,b%p,p) * lucas(a/p, b/p, p) % p;
}


int n;
LLong a, b, p;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld %lld %lld", &a, &b, &p);
        printf("%lld\n", lucas(a, b, p));
    }
    return 0;
}