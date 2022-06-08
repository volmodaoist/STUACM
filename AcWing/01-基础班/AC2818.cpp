#include<bits/stdc++.h>
using namespace std;

int n, m;
int ax[100005], bx[100005];

int main(){
    while(scanf("%d %d",&n, &m) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &ax[i]);            
        }
        for(int i = 0; i < m; i++){
            scanf("%d", &bx[i]);
        }
        int j = 0;
        for(int i  = 0; i < m; i++){
            if(j < n && ax[j] == bx[i]){
               j++; 
            }
        }
        printf("%s\n", j == n ? "Yes" : "No");
    }
    return 0;
}