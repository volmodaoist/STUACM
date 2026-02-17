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
#define  MAXN  600005

ill ans;
ii stk[MAXN];
int n, h[MAXN], top;

// 本题来自于 LG1823，本题难点在于如何处理等高个体
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &h[i]);
        ii hp{h[i], 1};
        while (top && h[i] >= stk[top].first) {
            ans += stk[top].second; 
            if (stk[top].first == h[i]) {
                hp.second += stk[top].second;
            }
            top--;
        }
        if(top) ans++;
        stk[++top] = hp;
    }

    printf("%lld\n", ans);
    return 0;
}