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

#define  MAXN  100005

int arr[MAXN], n;
void quick_sort(int arr[], int lo, int hi) {
    if (lo >= hi)
        return;
    int md = lo + (hi - lo) / 2;
    int x = arr[md], i = lo - 1, j = hi + 1;
    while(i < j){
        do i++; while (arr[i] < x);
        do j--; while (arr[j] > x);
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    quick_sort(arr, lo, j);
    quick_sort(arr, j + 1, hi);
}

int main(){ 
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}