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
#define  MAXN  100005


int kase;
int vol[MAXN], wgt[MAXN], pt[MAXN];
int dp[MAXN];

int find(int x) {
    return x != pt[x] ? pt[x] = find(pt[x]) : x;
}

int merge(int x, int y){
    int xr = find(x), yr = find(y);
    if(xr != yr){
        pt[xr] = yr;
        wgt[yr] += wgt[xr];
        vol[yr] += vol[xr];
        return 1;
    }
    return 0;
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, m, w, a, b;
    scanf("%d %d %d", &n, &m, &w);
    for (int i = 1; i <= n; i++)
        pt[i] = i;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &vol[i], &wgt[i]);
    }

    for (int i = 1; i <= m; i++){
        scanf("%d %d", &a, &b);
        merge(a, b);
    }
    
    
    set<int> clouds;
    for (int i = 1; i <= n; i++){
        clouds.insert(find(i));
    }


    for(auto i : clouds){
        for (int j = w; j >= vol[i]; j--){
            dp[j] = max(dp[j], dp[j - vol[i]] + wgt[i]);
        }
    }
    printf("%d\n", dp[w]);

    return 0;
}