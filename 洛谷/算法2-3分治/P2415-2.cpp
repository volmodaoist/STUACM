#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long llong;
typedef unsigned long long ull;
typedef pair<int, int> ii;

int main(){
    llong ans=0;
    int n = 0, t;
    while(scanf("%d",&t)!=EOF)
        ans += t, n++;
    ans = ans << (n - 1);
    printf("%lld", ans);
    return 0;
}