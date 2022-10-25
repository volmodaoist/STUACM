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

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, k, s[100];
    while (scanf("%d %d", &n, &k) != EOF){
        for (int i = 1; i <= n; i++){
            scanf("%d", &s[i]);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if(s[i] >= s[k] && s[i] > 0){
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}s