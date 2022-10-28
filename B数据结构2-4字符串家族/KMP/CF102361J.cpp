#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
 
 
typedef long long ill;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
#define  MAXN  20000005
 
 
int nxt[MAXN];
char str[MAXN], pat[MAXN];
 
void calc_next(char str[MAXN], int n){
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && str[i] != str[j + 1]) {
            j = nxt[j];
        }
        if (str[i] == str[j + 1])
            j++;
        nxt[i] = j;
    }
}
 
// https://codeforces.com/gym/102361/problem/J
int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif
 
    ill a, b;
    scanf("%lld %lld", &a, &b);
    scanf("%s", str + 1);
    
    int slen = strlen(str + 1), plen = 0;
    for (int i = slen; i >= 1; i--) {
        if(str[i] == '.'){
            break;
        }
        pat[++plen] = str[i];
    }
 
    int n = strlen(pat + 1);
    
    calc_next(pat, plen);
    ill ans = INT_MIN;
    for (int i = 1; i <= plen; i++) {
        ans = max(ans, a * i - b * (i - nxt[i]));
    }
    printf("%lld\n", ans);
    return 0;
}