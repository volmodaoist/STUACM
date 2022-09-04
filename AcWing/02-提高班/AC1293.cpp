#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000005
int n, x;
int excl[MAXN], primes[MAXN], cnt;
void eular(int n){
    for(int i = 2; i <= n; i++){
        if(!excl[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] <= n / i; j++){
            excl[primes[j] * i] = 1;
            if(i % primes[j] == 0) break;
        }
    }
}

int main(){
    eular(1000000);
    scanf("%d", &n);
    printf("%d\n", n <= 2 ? 1 : 2);
    for(int i = 1; i <= n; i++){
        printf("%d ", !excl[i + 1] ? 1 : 2);
    }
    return 0;
}