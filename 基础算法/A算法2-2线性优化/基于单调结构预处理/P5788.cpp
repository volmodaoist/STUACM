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

int arr[MAXN];
int stk[MAXN], nex[MAXN], top;

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= n; i++){
        while(top && arr[i] > arr[stk[top]]){
            nex[stk[top--]] = i;
        }
        stk[++top] = i;
    }
    for (int i = 1; i <= n; i++){
        printf("%d ", nex[i]);
    }
    printf("\n");
    return 0;
}