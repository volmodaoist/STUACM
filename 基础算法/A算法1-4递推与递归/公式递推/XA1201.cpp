#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	min4(x,y,u,v)	(min(min(x,y),min(u,v)))
#define	max4(x,y,u,v)	(max(max(x,y),max(u,v)))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  inserter(x, x.begin())
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <iomanip>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
#define MAXN   5000

ull memo[MAXN] = {0, 1, 1};
ull fib(ull x){
    if(x==1 || x==2)
        return 1;
    if (memo[x] != 0)
        return memo[x];
    memo[x] = fib(x - 1) + fib(x - 2);
    return memo[x];
}

int kase, x;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif

    cin >> kase;
    while(kase--){
        cin >> x;
        cout << fib(x) << endl;
    }
    return 0;
}