
#include <bits/stdc++.h>
#include <limits>
using namespace std;

typedef long long ill;
typedef unsigned long long ull;
#define MAXN 100005

int arr[MAXN], n;

void quick_sort(int arr[], int lo, int hi){
    if(lo >= hi)
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
    while (scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        quick_sort(arr, 0, n - 1);
        for (int i = 0; i < n; i++){
            printf("%d ", arr[i]);
        }
    }

    return 0;
}