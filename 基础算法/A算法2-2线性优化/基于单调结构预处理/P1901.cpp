#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
#define  MAXN  3000005


int n, h[MAXN], v[MAXN];
int stk[MAXN], prec[MAXN], succ[MAXN], recv[MAXN];

int main(){ 
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d %d", &h[i], &v[i]);
    }

    for (int i = 1, top = 0; i <= n; i++) {
        while(top && h[i] > h[stk[top]]){
            succ[stk[top--]] = i;
        }
        stk[++top] = i;
    }

    for (int i = n, top = 0; i >= 1; i--) {
        while(top && h[i]  > h[stk[top]]){
            prec[stk[top--]] = i;
        }
        stk[++top] = i;
    }
    
    for (int i = 1; i <= n; i++) {
        recv[prec[i]] += v[i];
        recv[succ[i]] += v[i];
        // printf("prec = %d, succ = %d", prec[i], succ[i]);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, recv[i]);
    }
    printf("%d\n", ans);
    return 0;
}