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

int n, a, b, c, op;
ill s[MAXN], atg[MAXN];
int L[MAXN], R[MAXN], pos[MAXN];
vector<ill> v[MAXN];

void build() {
    int t = sqrt(n * 1.0);
    int blocks = (n / t) + (n % t != 0);
    for (int i = 1; i <= blocks; i++) {
        L[i] = (i - 1) * t + 1;
        R[i] = i * t;
    }
    R[blocks] = n;
    for (int i = 1; i <= blocks; i++) {
        for (int j = L[i]; j <= R[i]; j++){
            pos[j] = i;
            v[i].push_back(s[j]);
        }
        sort(v[i].begin(), v[i].end());
    }
}

void reset(int x){
    v[x].clear();
    for (int i = L[x]; i <= R[x]; i++){
        v[x].push_back(s[i]);
    }
    sort(v[x].begin(), v[x].end());
}


void update(int lo, int hi, int c){
    int p = pos[lo], q = pos[hi];
    if (p == q){
        for (int i = lo; i <= hi; i++){
            s[i] += c;
        }
        reset(p);
    } else {
        for (int i = lo; i <= R[p]; i++) {
            s[i] += c;
        }
        reset(p);
        for (int i = L[q]; i <= hi; i++){
            s[i] += c;
        }
        reset(q);
        for (int i = p + 1; i <= q - 1; i++){
            atg[i] += c;
        }
    }
}


ill query(int lo, int hi, ill c){
    ill ans = INT_MIN;
    int p = pos[lo], q = pos[hi], fg = 0;
    if (p == q) {
        for (int i = lo; i <= hi; i++){
            if(s[i] + atg[p] < c){
                ans = max(ans, s[i] + atg[p]);
                fg = 1;
            }
        }
    } else {
        for (int i = lo; i <= R[p]; i++){
            if(s[i] + atg[p] < c){
                ans = max(ans, s[i] + atg[p]);
                fg = 1;
            }
        }
        for (int i = L[q]; i <= hi; i++){
            if(s[i] + atg[q] < c){
                ans = max(ans, s[i] + atg[q]);
                fg = 1;
            }
        }
        for (int i = p + 1; i <= q - 1; i++){
            ill t = c - atg[i];
            int k = lower_bound(v[i].begin(), v[i].end(), t) - v[i].begin();
            if(k > 0 && v[i][k - 1] + atg[i] < c){
                ans = max(ans, v[i][k - 1] + atg[i]);
                fg = 1;
            }
        }
    }
    return fg ? ans : -1;
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%lld", &s[i]);
    }
    build();
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d %d", &op, &a, &b, &c);
        if (op == 0) {
            update(a, b, c);
        } else if (op == 1) {
            printf("%lld\n", query(a, b, c));
        }
    }

    return 0;
}