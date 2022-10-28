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


typedef long long LLong;
typedef unsigned long long ULL;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
#define  fi    first
#define  se    second
#define  MAXN  100005

char s[MAXN];
char p[MAXN];

int nxt[MAXN];
int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    while (scanf("%s", s + 1) != EOF) {
        memset(nxt, 0, sizeof(nxt));
        if (strcmp(s + 1, "#") == 0)
            break;
        scanf("%s", p + 1);
        
        // printf("%s", s + 1);
        // printf("%s", p + 1);

        int n = strlen(s + 1);
        int m = strlen(p + 1);
        for (int i = 2, j = 0; i <= m; i++){
            while (j && p[i] != p[j + 1])
                j = nxt[j];
            if (p[i] == p[j + 1])j++;
            nxt[i] = j;
        }
        int cnt = 0;
        for (int i = 1, j = 0; i <= n; i++) {
            while (j && s[i] != p[j + 1])
                j = nxt[j];
            if (s[i] == p[j + 1])
                j++;
            if(j == m){
                cnt++, j = 0;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}