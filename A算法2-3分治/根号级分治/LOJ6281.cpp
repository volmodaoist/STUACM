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

int op, a, b, c, n;
int s[MAXN], sumv[MAXN], L[MAXN], R[MAXN], pos[MAXN];
int flag[MAXN];

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

// 如果块内元素都已经变成 1，说明已经不用开平方了
void block_sqrt(int x){
    if(flag[x]){
        return;
    }
    flag[x] = 1, sumv[x] = 0;
    for (int i = L[x]; i <= R[x]; i++){
        s[i] = sqrt(s[i]);
        sumv[x] += s[i];
        if (s[i] > 1) {
            flag[x] = 0;
        }
    }
}

void update(int lo, int hi){
    int p = pos[lo], q = pos[hi];
    if(p == q){
        for (int i = lo; i <= hi; i++){
            sumv[p] -= s[i];
            s[i] = sqrt(s[i]);
            sumv[p] += s[i];
        }
    }else{
        for (int i = lo; i <= R[p]; i++){
            sumv[p] -= s[i];
            s[i] = sqrt(s[i]);
            sumv[p] += s[i];
        }
        for (int i = L[q]; i <= hi; i++){
            sumv[q] -= s[i];
            s[i] = sqrt(s[i]);
            sumv[q] += s[i];
        }
        for (int i = p + 1; i <= q - 1; i++){
            block_sqrt(i);
        }
    }
}

int query(int lo, int hi){
    int p = pos[lo], q = pos[hi], ans = 0;
    if (p == q) {
        for (int i = lo; i <= hi; i++){
            ans += s[i];
        }
    }else{
        for (int i = lo; i <= R[p]; i++){
            ans += s[i];
        }
        for (int i = L[q]; i <= hi; i++){
            ans += s[i];
        }
        for (int i = p + 1; i <= q - 1; i++){
            ans += sumv[i];
        }
    }
    return ans;
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
    build();
    for (int i = 1; i <= n; i++){
        scanf("%d %d %d %d", &op, &a, &b, &c);
        if(op == 0){
            update(a, b);
        } else if (op == 1) {
            printf("%d\n", query(a, b));
        }
    }
    return 0;
}