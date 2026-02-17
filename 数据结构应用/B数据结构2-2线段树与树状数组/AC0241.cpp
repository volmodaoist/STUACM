#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


#define MAXN  200005
typedef long long llong;

int n, x, tree[MAXN], p[MAXN], lo[MAXN], hi[MAXN];
int lowbit(int x){
    return x & (-x);
}
void update(int x, int c){
    for(int i = x; i <= n; i+= lowbit(i)){
        tree[i] += c;
    }
}

int query(int x){
    int ans = 0;
    for(int i = x; i; i-=lowbit(i)){
        ans += tree[i];
    }
    return ans;
}


int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &p[i]);
    }
    for(int i = 1;  i <= n; i++){
        lo[i] = query(p[i] - 1);        // 小于p[i]
        hi[i] = query(n) - query(p[i]); // 大于p[i] 
        update(p[i], 1);
    }
    
    memset(tree, 0, sizeof(tree));

    // 楼兰图腾这题感觉就是逆序对问题的变体，只不过是前序一趟，后续一趟，两趟相乘即可 
    llong ans1 = 0, ans2 = 0;
    for(int i = n; i >= 1; i--){
        ans1 += 1LL * hi[i] * (query(n) - query(p[i]));
        ans2 += 1LL * lo[i] * query(p[i] - 1);
        update(p[i], 1);
    }
    printf("%lld %lld\n", ans1, ans2);
    return 0;
}