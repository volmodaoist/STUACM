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


typedef long long Long;
typedef unsigned long long ULL;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  fi    first
#define  se    second
#define  MAXN  100005

int n, m, arr[MAXN];
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    while (scanf("%d %d", &n, &m) != EOF){
        for (int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        sort(arr, arr + n);
        for (int i = 0; i < m; i++){
            printf("%d%s", arr[i], ((i != m - 1) ? " " : "\n"));
        }
    }

    return 0;
}