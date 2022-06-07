#include<bits/stdc++.h>
using namespace std;

int n,m,l,r;
int arr[100005];

int main(){
    while(scanf("%d %d", &n, &m) != EOF){
        for(int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
            arr[i] += arr[i - 1];
        }
        for(int i = 1; i <= m; i++){
            scanf("%d %d", &l, &r);
            printf("%d\n", arr[r] - arr[l - 1]);
        }
    }
    return 0;
}