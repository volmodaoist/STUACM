#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	CLEAR(A,x)  (memset(A,x,sizeof(A)))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long llong;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
#define  MAXN  600005

typedef struct _TreeNode{
    int lo, hi;
    double val, s, c;
} TreeNode;

TreeNode tr[MAXN];
double v[MAXN];

void build(int lo, int hi, int k = 1){

}

void update(int lo, int hi, int c, int k = 1){

}

double query(int lo, int hi, int k = 1){

}

int n, m, op, a, b, c;
int main() {
#ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++){
        scanf("%d", &op);
        if(op == 1){
            scanf("%d %d %d", &a, &b, &c);
            update(a, b, c);
        } else if (op == 2) {
            scanf("%d %d", &a, &b);
            printf("%.1lf", query(a, b));
        }
    }
    return 0;
}