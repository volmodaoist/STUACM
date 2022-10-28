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
#define  MAXN  800005

int flaw[MAXN], n;

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &flaw[i]);
        flaw[n + i] = flaw[i];
    }

    int i = 1, j = 2, k = 0;
    while (i <= n && j <= n) {
        for (k = 0; k < n && flaw[i + k] == flaw[j + k]; k++);
        if (flaw[i + k] > flaw[j + k]) {
            i = i + k + 1;
        } else {
            j = j + k + 1;
        }
        if(i == j) j++;
    }
    int idx = min(i, j);
    for (int i = idx, len = 1; len <= n; i++, len++){
        printf("%d ", flaw[i]);
    }
    printf("\n");
    return 0;
}