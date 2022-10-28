#include<bits/stdc++.h>
using namespace std;

int n;
int arr[100005];

void quick_sort(int arr[], int lo, int hi){
    if(lo >= hi)
        return;
    int md = lo + (hi - lo) / 2;
    int x = arr[md], i = lo - 1, j = hi + 1;
    while(i < j){
        do i++; while(arr[i] < x);
        do j--; while(arr[j] > x);
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    quick_sort(arr, lo,  j);
    quick_sort(arr, j + 1, hi);
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    quick_sort(arr, 0, n - 1);
    for(int i = 0; i < n; i++){
        printf("%d%s",arr[i], ((i == n - 1) ? "\n" : " "));
    }
    return 0;
}