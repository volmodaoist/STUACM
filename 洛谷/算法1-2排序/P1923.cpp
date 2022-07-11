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
#define  MAXN  5000005 

int arr[MAXN];
int quick_sort(int arr[], int lo, int hi, int k){
    if (lo >= hi)
        return arr[lo];
    int md = lo + (hi - lo) / 2, i = lo - 1, j = hi + 1;
    int x = arr[md];
    while(i < j){
        do i++; while (arr[i] < x);
        do j--; while (arr[j] > x);
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    if (j - lo + 1 >= k){
        return quick_sort(arr, lo, j, k);
    }else{
        return quick_sort(arr, j + 1, hi, k - (j - lo + 1));
    }
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("%d\n", quick_sort(arr, 0, n - 1, k + 1));
    return 0;
}