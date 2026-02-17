#include<bits/stdc++.h>
using namespace std;

int n,m,q,l,r;
int arr[2000][2000];

int main(){
    while(scanf("%d %d %d", &n, &m, &q) != EOF){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <=m ; j++){
                scanf("%d", &arr[i][j]);
                arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
            }
        }
        int x1,y1,x2,y2;
        while(q--){
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            printf("%d\n", arr[x2][y2] - arr[x2][y1 - 1] - arr[x1 - 1][y2] + arr[x1 - 1][y1 - 1]);
        }
    }
    return 0;
}