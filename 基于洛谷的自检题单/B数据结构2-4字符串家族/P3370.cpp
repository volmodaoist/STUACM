#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
#define  MAXN  100005

char s[MAXN];
ull H[MAXN], T[MAXN], n , p = 13331, len;

// 本题是一个字符串哈希模板题
ull hash_in(char s[]) {
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        H[i] = H[i - 1] * p + s[i];
    }
    return H[n];
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    
    scanf("%llu", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s + 1);
        T[i] = hash_in(s);
    }
    sort(T, T + n);
    int len = 0;
    for (int i = 1; i < n; i++) {
        if (T[i] != T[len]){
            T[++len] = T[i];
        }
    }
    printf("%d\n", len + 1);
    return 0;
}