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
#define  MAXN  100005

int a, b, c, n, op;
int seq[MAXN], pos[MAXN], atg[MAXN], L[MAXN], R[MAXN];
vector<int> v[MAXN];

void build(){
    int t = sqrt(n * 1.0);
    int blocks = (n / t) + (n % t != 0);
    for (int i = 1; i <= blocks; i++) {
        L[i] = (i - 1) * t + 1;
        R[i] = i * t;
    }
    R[blocks] = n;
    for (int i = 1; i <= blocks; i++){
        for (int j = L[i]; j <= R[i]; j++){
            pos[j] = i;
            v[i].push_back(seq[j]);
        }
        sort(v[i].begin(), v[i].end());
    }
}

void reset(int x){
    v[x].clear();
    for (int i = L[x]; i <= R[x]; i++){
        v[x].push_back(seq[i]);
    }
    sort(v[x].begin(), v[x].end());
}


void update(int lo, int hi, ill c){
    int p = pos[lo], q = pos[hi];
    if (p == q){
        for (int i = lo; i <= hi; i++){
            seq[i] += c;
        }
        reset(p);
    }else{
        for (int i = lo; i <= R[p]; i++){
            seq[i] += c;
        }
        reset(p);
        for (int i = L[q]; i <= hi; i++){
            seq[i] += c;
        }
        reset(q);
        for (int i = p + 1; i <= q - 1; i++){
            atg[i] += c;
        }
    }
}

ill query(int lo, int hi, ill c){
    ill ans = 0;
    int p = pos[lo], q = pos[hi];
    if (p == q) {
        for (int i = lo; i <= hi; i++){
            if(seq[i] + atg[p] < c){
                ans++;
            }
        }
    }else{
        for (int i = lo; i <= R[p]; i++){
            if(seq[i] + atg[p] < c){
                ans++;
            }
        }
        for (int i = L[q]; i <= hi; i++){
            if(seq[i] + atg[q] < c){
                ans++;
            }
        }
        for (int i = p + 1; i <= q - 1; i++){
            ans += (lower_bound(v[i].begin(), v[i].end(), c - atg[i]) - v[i].begin());
        }
    }
    return ans;
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &seq[i]);
    }
    build();
    /*
    for (int i = 1; i <= n; i++){
        printf("pos[%d] = %d, L = %d, R = %d\n", i, pos[i], L[i], R[i]);
    }
    */
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &op, &a, &b, &c);
        if (op == 0) {
            update(a, b, c);
        } else if (op == 1) {
            printf("%lld\n", query(a, b, 1LL * c * c));
        }
    }

    return 0;
}