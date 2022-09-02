#include<bits/stdc++.h>
using namespace std;


// 每个整数 n 都可以写成质因数乘积的形式
void get_prime_factor(int n){
    int sn = sqrt(n);
    for(int i = 2; i <= sn; i++){
        // 若非需要打印信息，这条判断其实是可以删掉的，参考AC0870，AC0871
        // 因为遍历达到 i 意味着前面 2 ~ i-1 范围之内的质因数都已经被除干净了
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