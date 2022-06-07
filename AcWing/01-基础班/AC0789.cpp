#include<bits/stdc++.h>
using namespace std;

int n, q, k;
int arr[100005];

int lower_search(int arr[], int k){
    int lo = 0, hi = n - 1;
    while(lo < hi){
        int md = lo + (hi - lo) / 2;
        if(arr[md] >= k){
            hi = md;
        }else{
            lo = md + 1;
        }
    }
    return arr[lo] == k ? lo : -1;
}

int upper_search(int arr[], int k){
    int lo = 0, hi = n - 1;
    while(lo < hi){
        int md = lo + (hi - lo + 1) / 2;
        if(arr[md] <= k){
            lo = md;
        }else{
            hi = md - 1;
        }
    }
    return arr[lo] == k ? lo : -1;
}

int main(){
    while(scanf("%d %d",&n,&q) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        while(q--){
            scanf("%d",&k);
            printf("%d %d\n", lower_search(arr, k), upper_search(arr, k));
        }
    }
    return 0;
}