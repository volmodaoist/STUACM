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


// https://codeforces.com/contest/1343/problem/B
int kase, n;
int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d", &kase);
    while(kase--){
        scanf("%d", &n);
        if (n % 4 == 0){
            printf("YES\n");
            vector<int> ans;
            for (int i = 2; i <= n; i += 2) {
                ans.push_back(i);
            }
            for (int i = 1; i <= n; i += 2){
                ans.push_back(i);
            }
            ans[ans.size() - 1] += n / 2;
            for (int i = 0; i < ans.size(); i++){
                printf("%d ", ans[i]);
            }
            printf("\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}