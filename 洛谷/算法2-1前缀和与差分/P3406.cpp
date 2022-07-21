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
#include <limits>
using namespace std;


typedef long long Long;
typedef unsigned long long ULL;
typedef pair<int, int> ii;
#define  fi    first
#define  se    second
#define  MAXN  100005

int n, m;
Long p[MAXN], s[MAXN];

int main(){
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    while (scanf("%d %d", &n, &m) != EOF){
        memset(s, 0, sizeof(0));
        for (int i = 1; i <= m; i++){
            scanf("%lld", &p[i]);
        }
        for (int i = 1; i < m; i++){
            int a = min(p[i], p[i + 1]);
            int b = max(p[i], p[i + 1]);
            s[a]++;
            s[b]--;
        }
        for (int i = 1; i <= n; i++){
            s[i] += s[i - 1];
        }
        Long ans = 0;
        Long a, b, c;
        for (int i = 1; i < n; i++){
            scanf("%lld %lld %lld", &a, &b, &c);
            ans += min(a * s[i], c + b * s[i]);
        }
        printf("%lld\n", ans);
    }

    return 0;
}