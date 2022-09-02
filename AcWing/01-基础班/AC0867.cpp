#include<bits/stdc++.h>
using namespace std;


// 每个整数 n 都可以写成质因数乘积的形式
void get_prime_factor(int n){
    int sn = sqrt(n);
    for(int i = 2; i <= sn; i++){
        if(n % i == 0){
            int s = 0;
            while(n % i == 0){
                 n = n / i;
                 s = s + 1;
            }
            printf("%d %d\n", i, s);
        }
    }
    if(n > 1){
        printf("%d %d\n", n, 1);
    }
    printf("\n");
}

int n, x;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        get_prime_factor(x);
    }
    return 0;
}