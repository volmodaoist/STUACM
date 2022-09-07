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
#include <limits>
using namespace std;


typedef long long llong;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
#define  fi    first
#define  se    second
#define  MAXN  100005

int n, m, p;
int fib[MAXN], cnt;
int memo[MAXN];

// 打表处理斐波那契数列
void init_fib() {
    fib[1] = 1, fib[2] = 2;
    for (int i = 3;  fib[i] <= 1000; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

int sg(int x){
    if (memo[x] != -1){
        return memo[x];
    }
    unordered_set<int> ss;
    for (int i = 1; fib[i] <= x; i++) {
        ss.insert(sg(x - fib[i]));
    }
    for (int i = 0 ; ; i++){
        if(!ss.count(i)){
            memo[x] = i;
            break;
        }
    }
    return memo[x];
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    init_fib();
    memset(memo, -1, sizeof(memo));
    while (scanf("%d %d %d", &n, &m, &p) != EOF) {
        if (n == 0 && m == 0 && p == 0)
            break;
        int ans = sg(n) ^ sg(m) ^ sg(p);
        printf("%s\n", ans ? "Fibo" : "Nacci");
    }

    return 0;
}