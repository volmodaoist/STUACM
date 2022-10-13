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


typedef long long llong;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
#define  MAXN  100005


char in_order[MAXN];
char pre_order[MAXN];

void dfs(int lo, int hi, int pl, int ph) {
    if (lo > hi || pl > ph) 
        return;
    int t = 0;
    char root = pre_order[pl];
    for (int i = lo; i <= hi; i++) {
        if(in_order[i] == root){
            // cout << root << endl;
            t = i;
            break;
        }
    }
    dfs(lo, t - 1, pl + 1, pl + t - lo);
    dfs(t + 1, hi, pl - lo + t + 1, ph);
    printf("%c", root);
}


int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%s", in_order + 1);
    scanf("%s", pre_order + 1);
    
    int n = strlen(in_order + 1);

    dfs(1, n, 1, n);

    return 0;
}