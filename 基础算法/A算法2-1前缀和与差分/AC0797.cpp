#include<bits/stdc++.h>
using namespace std;

int n,m,l,r,c;
int arr[100005], diff[100005];

int main(){
    while(scanf("%d %d", &n, &m) != EOF){
        for(int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
            diff[i] = arr[i] - arr[i - 1];
        }
        for(int i = 1; i <= m; i++){
            scanf("%d %d %d", &l, &r,&c);
            diff[l]+=c;
            diff[r+1]-=c;
        }
        for(int i = 1; i <= n; i++){
            diff[i] = diff[i] + diff[i - 1];
            printf("%d%s", diff[i], ((i == n) ? "\n" : " "));
        }
    }
    return 0;
}