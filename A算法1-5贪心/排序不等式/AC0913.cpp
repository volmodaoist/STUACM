#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
typedef long long ill;

int n;
int arr[MAXN];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);  
    }
    sort(arr, arr + n);
    ill ans = 0;
    for(int i = 0; i < n; i++){
        ans += (arr[i] * (n - i - 1));
    }
    printf("%lld\n", ans);
    return 0;
}