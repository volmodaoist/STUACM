#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

typedef long long llong;

int main(){
    llong a, b, p;
    scanf("%lld %lld %lld", &a, &b, &p);
    llong ans = 0; 
    while(b){
        if(b & 1) ans = (ans + a) % p;
        a = (a + a) % p;
        b >>= 1;
    }
    cout << ans << endl; 
    return 0;
}