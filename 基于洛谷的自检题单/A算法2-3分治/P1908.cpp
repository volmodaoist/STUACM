#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
#define  MAXN  500005

int n, arr[MAXN], tmp[MAXN];

ill merge_sort(int arr[MAXN], int lo, int hi){
    if(lo >= hi)
        return 0;
    int md = lo + (hi - lo) / 2;

    ill cross = 0;
    ill lt = merge_sort(arr, lo, md);
    ill rt = merge_sort(arr, md + 1, hi);

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

    ill ans = merge_sort(arr, 0, n - 1);
    printf("%lld\n", ans);
    return 0;
}