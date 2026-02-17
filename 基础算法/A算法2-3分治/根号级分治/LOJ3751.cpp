#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


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
#define  MAXN  1000005


int n, m, a, b, c;
int s[MAXN], pos[MAXN], L[MAXN], R[MAXN];
int cnt[MAXN], ans[MAXN];


typedef struct _query{
    int lo, hi, id;
    bool operator< (const struct _query &other) const{
        if(pos[lo] ^ pos[other.lo]){
            return pos[lo] < pos[other.lo];
        } else{
            if(pos[lo] & 1){
                return pos[hi] < pos[other.hi];
            }else{
                return pos[hi] > pos[other.hi];
            }
        }
    }
} Query;

Query q[MAXN];

void build(){
    int t = sqrt(n * 1.0);
    int blocks = (n / t) + (n % t != 0);
    for (int i = 1; i <= blocks; i++){
        L[i] = (i - 1) * t + 1;
        R[i] = i * t;
    }
    R[blocks] = n;
    for (int i = 1; i <= blocks; i++){
        for (int j = L[i]; j <= R[i]; j++){
            pos[j] = i;
        }
    }
}


int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &s[i]);
    }
    scanf("%d", &m);
    int qx, qy;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &qx, &qy);
        q[i].lo = qx, q[i].hi = qy;
        q[i].id = i;
    }
    sort(q + 1, q + m + 1);
    int x = 1, y = 0, now = 0;
    for (int i = 1; i <= m; i++) {
        qx = q[i].lo, qy = q[i].hi;
        while(x < qx) now -= !--cnt[s[x++]];
        while(x > qx) now += !cnt[s[--x]]++;
        while(y < qy) now += !cnt[s[++y]]++;
        while(y > qy) now -= !--cnt[s[y--]];
        ans[q[i].id] = now;
    }
    for (int i = 1; i <= m; i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}