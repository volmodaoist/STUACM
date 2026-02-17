#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
#define  MAXN  100005


ill quick_pow(ill a ,ill b, ill p){
    ill ans = 1;
    while(b){
        if(b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    ill a, b, p;
    scanf("%lld %lld %lld",&a,&b,&p);
    printf("%lld^%lld mod %lld=%lld\n", a, b, p, quick_pow(a, b, p));
    return 0;
}