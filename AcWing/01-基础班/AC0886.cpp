#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	CLEAR(A,x)  (memset(A,x,sizeof(A)))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))

#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
typedef long long LLong;

LLong n, a, b, MOD = 1e9 + 7;
LLong fact[MAXN], invfact[MAXN];

LLong quick_pow(LLong a, LLong b, LLong p){
    LLong ans = 1;
    while(b){
        if(b & 1){
            ans = ans * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

// 预处理一下
void solve(){
    fact[0] = invfact[0] = 1;
    for(int i = 1; i <= 100000; i++){
        fact[i] = fact[i - 1] * i % MOD;
        invfact[i] = invfact[i - 1] * quick_pow(i, MOD - 2, MOD) % MOD;
    }
}

int main(){
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    solve();
    scanf("%lld", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", fact[a] * invfact[b] % MOD * invfact[a - b] % MOD);
    }
    return 0;
}