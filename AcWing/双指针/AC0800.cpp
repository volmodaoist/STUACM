#include<bits/stdc++.h>
using namespace std;

int n, m, x;
int ax[100005], bx[100005];

int main(){
    while(scanf("%d %d %d", &n, &m, &x) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &ax[i]);
        }
        for(int i = 0; i < m; i++){
            scanf("%d", &bx[i]);
        }
        for(int i = 0, j = m - 1; i < n; i++){
            while(j >= 0 && ax[i] + bx[j] > x){
                j--;
            }
            if(ax[i] + bx[j] == x){
                printf("%d %d\n", i, j);
                break;
            }
        }

        
    }    
    return 0;
}