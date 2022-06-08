#include<bits/stdc++.h>
using namespace std;

int n,m,q,l,r,x;
int arr[2000][2000];
int diff[2000][2000];

// 把原始矩阵每个元素的数值视为(i,j)~(i,j)增量, 用以构造差分矩阵
void insert(int x1, int y1, int x2, int y2, int c){
    diff[x1][y1] += c;
    diff[x1][y2 + 1] -=c;
    diff[x2 + 1][y1] -=c;
    diff[x2 + 1][y2 + 1] +=c;
}

int main(){
    while(scanf("%d %d %d", &n, &m, &q) != EOF){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <=m ; j++){
                scanf("%d", &arr[i][j]);
                insert(i, j, i, j, arr[i][j]);
            }
        }
        int x1,y1,x2,y2,c;
        while(q--){
            scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2,&c);
            insert(x1, y1, x2, y2, c);
        }
         for(int i = 1; i <= n; i++){
            for(int j = 1; j <=m ; j++){
                diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <=m ; j++){
                printf("%d ", diff[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}