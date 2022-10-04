#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	CLEAR(A,x)  (memset(A,x,sizeof(A)))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long llong;
typedef unsigned long long ull;

#define  MAXN  100005

llong quick_pow(llong a, llong b, llong p){
    llong ans = 1;
    while(b){
        if(b & 1)ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

llong m, n;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int p = 100003;
    scanf("%lld %lld",&m, &n);
    llong a = quick_pow(m, n, p) % p;
    llong b = m * quick_pow(m - 1, n - 1, p) % p;
    llong c = (a - b + p) % p;
    printf("%lld\n", c);


    return 0;
}