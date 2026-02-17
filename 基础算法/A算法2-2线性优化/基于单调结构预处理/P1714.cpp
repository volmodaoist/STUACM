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
#define  MAXN  600005

int p[MAXN], s[MAXN];
int deq[MAXN], head = 0, tail = -1;

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++ ){
        scanf("%d", &p[i]);
    }

    for (int i = 0; i < n; i++){
        s[i + 1] = s[i] + p[i];
    }
    int ans = -2e9;
    deq[++tail] = 0;
    for (int i = 1; i <= n; i++) {
        while(head <= tail && i - deq[head] > m){
            head++;
        }
        ans = max(ans, s[i] - s[deq[head]]);
        while (head <= tail && s[i] <= s[deq[tail]]){
            tail--;
        }
        deq[++tail] = i;
    }
    printf("%d\n", ans);
    return 0;
}