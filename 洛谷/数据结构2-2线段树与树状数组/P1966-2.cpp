
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long llong;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;


#define  MAXN  100005

int mod = 1e8 - 3;
int n, a[MAXN], b[MAXN], c[MAXN], ranks[MAXN];

void read(int n, int arr[MAXN], int rank[MAXN]){
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        ranks[i] = i;
    }
    stable_sort(ranks + 1, ranks + n + 1,  [&](int i, int j){
        return arr[i] < arr[j];
    });
    for (int i = 1; i <= n; i++){
        arr[i] = ranks[i];
    }
}

llong tr[MAXN];
inline int lowbit(int x) {
    return x & (-x);
}

inline llong query(int x){
    llong ans = 0;
    for (int i = x; i; i -= lowbit(i)) {
        ans = (ans + tr[i]) % mod;
    }
    return ans;
}

inline void update(int x, int c){
    for (int i = x; i <= n; i += lowbit(i)) {
        tr[i] += c;
    }
}

int main(){ 
    scanf("%d", &n);
    read(n, a, ranks);
    read(n, b, ranks);

    for (int i = 1; i <= n; i++){
        c[a[i]] = b[i];
        ranks[i] = i;
    }
    stable_sort(ranks + 1, ranks + 1 + n, [&](int i, int j){
        return c[i] < c[j]; 
    });

    llong ans = 0;
    for (int i = 1; i <= n; i++) {
        update(ranks[i], 1);
        ans = (ans + query(ranks[i])) % mod;
    }

    // 所有可能的序对 C(n, 2) 然后减掉正序、等序的数对即可
    printf("%lld\n", ((1LL * n * (n + 1) / 2 % mod) - (ans % mod) + mod) % mod);
    return 0;
}