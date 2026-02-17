#include<bits/stdc++.h>
using namespace std;
// 小于一百万的偶数
#define MAXN 1000005
int excl[MAXN], primes[MAXN], cnt;

void eular(int n){
    for(int i = 2; i <= n; i++){
        if(!excl[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] <= n / i; j++){
            excl[i * primes[j]] = 1;
            if(i % primes[j] == 0) break;
        }
    }   
}

int n;
int main(){
    // 先用欧拉筛扫描一趟获取小于等于 1000000 所有素数
    eular(1000000);
    // 然后再对素数数组来求两数之和
    map<int, int> hs;
    for(int i = 0; i < cnt; i++){
        hs[primes[i]] = i;
    }
    
    while(scanf("%d", &n) && n){
        for(int i = 0; i < cnt; i++){
            if(hs.count(n - primes[i])){
                printf("%d = %d + %d\n", n, primes[i], n - primes[i]);
                break;
            }
        }   
    }
    return 0;
}