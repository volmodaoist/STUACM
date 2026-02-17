#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;

#define  MAXN  100005

ill quick_pow(ill a, ill b, ill p){
    ill ans = 1;
    while(b){
        if(b & 1)ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

ill m, n;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int p = 100003;
    scanf("%lld %lld",&m, &n);
    ill a = quick_pow(m, n, p) % p;
    ill b = m * quick_pow(m - 1, n - 1, p) % p;
    ill c = (a - b + p) % p;
    printf("%lld\n", c);


    return 0;
}