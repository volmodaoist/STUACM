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
#define  MAXN  500005

int n, arr[MAXN], tmp[MAXN];

llong merge_sort(int arr[MAXN], int lo, int hi){
    if(lo >= hi)
        return 0;
    int md = lo + (hi - lo) / 2;

    llong cross = 0;
    llong lt = merge_sort(arr, lo, md);
    llong rt = merge_sort(arr, md + 1, hi);

    int i = lo, j = md + 1, k = 0;
    while (i <= md && j <= hi) {
        if(arr[i] <= arr[j]){
            tmp[k++] = arr[i++];
        }else{
            cross += (md - i + 1);
            tmp[k++] = arr[j++];
        }
    }
    while(i <= md) tmp[k++] = arr[i++];
    while(j <= hi) tmp[k++] = arr[j++];
    for (int i = 0; i < k; i++) {
        arr[lo + i] = tmp[i];
    }
    return cross + lt + rt;
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    llong ans = merge_sort(arr, 0, n - 1);
    printf("%lld\n", ans);
    return 0;
}