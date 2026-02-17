#include<bits/stdc++.h>
using namespace std;

int n, k;
int arr[100005];

//直接使用快排算法复杂 nlog(n)但是其实可以更快
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
    // 上面这个while包裹的过程其实是快排的一个核心部件,名为 patition
    quick_sort(arr, lo, j);
    quick_sort(arr, j + 1, hi);
}


int patition(int arr[], int lo, int hi, int k){
    if(lo >= hi)
        return arr[lo];
    int md = lo + (hi - lo) / 2;
    int x = arr[md], i = lo - 1, j = hi + 1;
    while(i < j){
        do i++; while(arr[i] < x);
        do j--; while(arr[j] > x);
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    
    // 寻找第K大元素，由于x左侧元素全都小于x右侧元素, 
    // 因而如果左侧长度小于K，那么第K大的元素势必落在右侧, 
    // 此时寻找数组第K大元素等价于在其右侧寻找 第k-(j - lo + 1 )大的元素!

    if(j - lo + 1 >= k){
        return patition(arr, lo, j, k);
    }else{
        return patition(arr, j + 1, hi, k - (j - lo + 1));
    }
}





int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    // quick_sort(arr, 0, n - 1);

    int ret = patition(arr, 0, n - 1, k);
    printf("%d\n", ret);
    return 0;
}