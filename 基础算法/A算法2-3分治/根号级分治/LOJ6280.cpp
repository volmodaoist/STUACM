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

int n, a, b, c, op;
int L[MAXN], R[MAXN], pos[MAXN];
ill s[MAXN], atg[MAXN], sumv[MAXN];

void build(){
    int t = sqrt(n * 1.0);
    int blocks = (n / t) + (n % t != 0);
    for (int i = 1; i <= blocks; i++){
        L[i] = (i - 1) * t + 1;
        R[i] = i * t;
    }
    for (int i = 1; i <= blocks; i++){
        for (int j = L[i]; j <= R[i]; j++){
            pos[j] = i;
            sumv[i] += s[j];
        }
    }
}

void update(int lo, int hi, ill c){
    int p = pos[lo], q = pos[hi];
    if (p == q) {
        for (int i = lo; i <= hi; i++){
            s[i] += c;
        }
        sumv[p] += ((hi - lo + 1) * c);
    }else{
        for (int i = lo; i <= R[p]; i++){
            s[i] += c;
        }
        sumv[p] += ((R[p] - lo + 1) * c);
        for (int i = L[q]; i <= hi; i++){
            s[i] += c;
        }
        sumv[q] += ((hi - L[q] + 1) * c);
        for (int i = p + 1; i <= q - 1; i++){
            atg[i] += c;
        }
    }
}

int query(int lo, int hi, int c){
    ill ans = 0;
    int m = c + 1, p = pos[lo], q = pos[hi];
    if(p == q){
        for (int i = lo; i <= hi; i++){
            ans += s[i];
        }
        ans += ((hi - lo + 1) * atg[p]);
    } else {
        for (int i = lo; i <= R[p]; i++){
            ans += s[i];
        }
        ans += ((R[p] - lo + 1) * atg[p]);
        for (int i = L[q]; i <= hi; i++){
            ans += s[i];
        }
        ans += ((hi - L[q] + 1) * atg[q]);
        for (int i = p + 1; i <= q - 1; i++) {
            ans += sumv[i] + (R[i] - L[i] + 1) * atg[i];
        }
    }
    return ans % m;
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &s[i]);
    }

    build();
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &op, &a, &b, &c);
        if (op == 0) {
            update(a, b, c);
        } else if (op == 1) {
            printf("%d\n", query(a, b, c));
        }
    }
    return 0;
}