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
#define MAXN  1000

ull memo[MAXN][MAXN];

ull S(ull n, ull k){
    if(k <=0 || k > n)
        return 0;
    if (n == k || k == 1)
        return 1;
    memo[n][k] = S(n - 1, k - 1) + k * S(n - 1, k);
    return memo[n][k];
}


int main(){ 
    int n, k;
    while(cin >> n >> k){
        cout << S(n, k) << endl;
    }
    return 0;
}