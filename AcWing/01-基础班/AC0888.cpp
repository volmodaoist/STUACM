#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 5005
#define PFCT prime_factor
int excl[MAXN], primes[MAXN], cnt;
void get_primes(int n){
    for(int i = 2; i <= n; i++){
        if(!excl[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] <= n / i; j++){
            excl[i * primes[j]] = 1;
            if(i % primes[j] == 0) break;
        }
    }
}

int prime_factor(int n, int p){
    int ans = 0;
    while(n){
        ans += n / p;
        n = n / p;
    }
    return ans;
}

vector<int> mul(vector<int> &a, int b){
    int t = 0;
    vector<int> c;
    for(int i = 0; i < a.size(); i++){
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while(t){
        c.push_back(t % 10);
        t /= 10;
    }
    while(c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}

int a, b;
int main(){
    // 先做质因数分解,再做高精度相乘
    scanf("%d %d", &a, &b);
    get_primes(a);
    vector<int> ans;
    ans.push_back(1);
    for(int i = 0; i < cnt; i++){
        int alpha = PFCT(a, primes[i]) - PFCT(b, primes[i]) - PFCT(a - b, primes[i]);
        for(int j = 0; j < alpha; j++){
            ans = mul(ans, primes[i]);
        }
    }
    for(int i = ans.size() - 1;  i >= 0; i--){
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}