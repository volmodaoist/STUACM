#include<bits/stdc++.h>
using namespace std;


// 如何证明欧拉函数是一个积性函数呢?

int n, x;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        int res = x;
        for(int j = 2; j <= x / j; j++){
            if(x % j == 0){
                while(x % j == 0){
                    x = x / j;
                }   
                res = res / j * (j - 1);   
            }
        }
        if(x > 1){
            res = res / x * (x - 1);
        }
        printf("%d\n", res);
    }
    return 0;
}