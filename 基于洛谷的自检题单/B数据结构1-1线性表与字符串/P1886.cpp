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
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
#define  MAXN  3000005

int v[MAXN], q[MAXN];
int main() {
#ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, k, head, tail;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    head = 0, tail = -1;
    for (int i = 0; i < n; i++){
        if(head <= tail && i - q[head] + 1 > k){
            ++head;
        }
        while(head <= tail && v[q[tail]] > v[i]){
            --tail;
        }
        q[++tail] = i;
        if(i - k + 1 >= 0) printf("%d ", v[q[head]]);
    }
    printf("\n");

    head = 0, tail = -1;
    for (int i = 0; i < n; i++) {
        if(head <= tail && i - q[head] + 1 > k){
            ++head;
        }
        while(head <= tail && v[q[tail]] < v[i]){
            --tail;
        }
        q[++tail] = i;
        if(i - k + 1 >= 0) printf("%d ", v[q[head]]);
    }
    printf("\n");

    return 0;
}