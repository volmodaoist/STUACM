#include<bits/stdc++.h>
using namespace std;

typedef long long Long;

int n;
int arr[100005];
int tmp[100005];

Long rev_pair = 0;
void merge_sort(int arr[], int lo, int hi){
    if(lo >= hi)
        return;
    int md = lo + (hi - lo) / 2;
    
    merge_sort(arr, lo, md);
    merge_sort(arr, md + 1, hi);
    
    int k  = 0, i = lo, j = md + 1;
    while(i <= md && j <= hi){
        if(arr[i] <= arr[j]){
            tmp[k++] = arr[i++]; 
        }else{
            tmp[k++] = arr[j++];
            rev_pair += (md - i + 1);
        }
        
    }
    while(i <= md) tmp[k++] = arr[i++];
    while(j <= hi) tmp[k++] = arr[j++];
    for(k = 0, i = lo; i <= hi; k++, i++){
        arr[i] = tmp[k];
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    merge_sort(arr, 0, n - 1);
    printf("%lld\n",rev_pair);
    return 0;
}