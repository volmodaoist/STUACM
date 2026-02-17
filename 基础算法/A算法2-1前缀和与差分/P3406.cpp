#include <bits/stdc++.h>
#include <limits>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
typedef pair<int, int> ii;
#define  MAXN  100005


ill p[MAXN], s[MAXN], n, m;

int main(){
    while (scanf("%lld %lld", &n, &m) != EOF){
        memset(s, 0, sizeof(0));
        for (int i = 1; i <= m; i++){
            scanf("%lld", &p[i]);
        }
        for (int i = 1; i < m; i++){
            int a = min(p[i], p[i + 1]);
            int b = max(p[i], p[i + 1]);
            s[a]++;
            s[b]--;
        }
        for (int i = 1; i <= n; i++){
            s[i] += s[i - 1];
        }
        ill ans = 0;
        ill a, b, c;
        for (int i = 1; i < n; i++){
            scanf("%lld %lld %lld", &a, &b, &c);
            ans += min(a * s[i], c + b * s[i]);
        }
        printf("%lld\n", ans);
    }

    return 0;
}