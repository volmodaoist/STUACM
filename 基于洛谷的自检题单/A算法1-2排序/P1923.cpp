#include <bits/stdc++.h>
#include <limits>
using namespace std;

typedef long long ill;
typedef unsigned long long ull;
#define MAXN 5000005

int arr[MAXN], n, k;
int quick_sort(int arr[], int lo, int hi, int k) {
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

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("%d\n", quick_sort(arr, 0, n - 1, k + 1));
    return 0;
}