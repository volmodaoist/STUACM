#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define  fi    first
#define  se    second
#define  MAXN  500005

int pt[MAXN], d[MAXN], id;
unordered_map<int, int> mapping;

int get(int x) {
    if(!mapping.count(x)){
        mapping[x] = ++id;
    }
    return mapping[x];
}

int find(int x) {
    if(x != pt[x]){
        int rt = find(pt[x]);
        d[x] ^= d[pt[x]];
        pt[x] = rt;
    }
    
    // 上面 if 内部可能修改了 pt[x]，切勿返回 x
    return pt[x]; 
}


char type[5];
int n, m, a, b, t, ar, br;

int main() {
    scanf("%d %d", &n, &m);
    
    int ans = m;
    for (int i = 0; i <= 10 * m; i++)
        pt[i] = i;
        
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %s", &a, &b, type);
        a = get(a - 1);
        b = get(b);
        t = (type[0] == 'o' ? 1 : 0);
        
        ar = find(a);
        br = find(b);
        if (ar == br) {
            if ((d[a] ^ d[b]) != t) {
                ans = i - 1;
                break;
            }
        } else {
            pt[ar] = br;
            d[ar] = d[a] ^ d[b] ^ t;
        }
    }
    printf("%d\n", ans);
    return 0;
}