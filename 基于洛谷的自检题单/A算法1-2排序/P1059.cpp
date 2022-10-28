#include <bits/stdc++.h>
#include <limits>
using namespace std;


typedef long long Long;
typedef unsigned long long ULL;
#define  fi    first
#define  se    second
#define  MAXN  100005

int  n, arr[MAXN];
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    while (scanf("%d", &n) != EOF){
        for (int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        sort(arr, arr + n);
        int j = 0;
        for (int i = 1; i < n; i++){
            if(arr[j] < arr[i]){
                arr[++j] = arr[i];
            }
        }
        printf("%d\n", j + 1);
        for (int i = 0; i <= j; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    
    return 0;
}