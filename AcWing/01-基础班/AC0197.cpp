#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 1000005
int n, excl[MAXN], primes[MAXN], cnt;

void get_primes(int n){
    for(int i = 2; i <= n; i++){
        if(!excl[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] <= n / i; j++){
            excl[primes[j] * i] = 1;
            if(i % primes[j] == 0) break;
        }
    }
}

int main(){
    scanf("%d", &n);
    get_primes(n);
    for(int i = 0; i < cnt; i++){
        int tmp = n, p = primes[i], c = 0;
        while(tmp){
            c += tmp / p;
            tmp /= p;
        }
        printf("%d %d\n", p, c);
    }
    return 0;
}