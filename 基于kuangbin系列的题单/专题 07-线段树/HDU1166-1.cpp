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
typedef tuple<int, int, int> iii;
#define  fi    first
#define  se    second
#define  MAXN  500010

inline int lowbit(int x){
    return -x & x;
}

int a, b, n, ar[MAXN], tr[MAXN];

int query(int x){
    int ans = 0; 
    for(int i = x; i; i-=lowbit(i)){
        ans += tr[i];
    }
    return ans;
}

void update(int x, int c){
    for (int i = x; i <= n; i += lowbit(i)){
        tr[i] += c;
    }
}

int kase;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d", &kase);
    for (int k = 1; k <= kase; k++){
        memset(ar, 0, sizeof(ar));
        memset(tr, 0, sizeof(tr));
        
        printf("Case %d:\n", k);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            scanf("%d", &ar[i]);
            update(i, ar[i]);
        }
        char op[10];
        while (scanf("%s", op) != EOF){
            if(op[0] == 'Q'){
                scanf("%d %d", &a, &b);
                printf("%d\n", query(b) - query(a - 1));
            }else if(op[0] == 'A'){
                scanf("%d %d", &a, &b);
                update(a, b);
            }else if(op[0] == 'S'){
                scanf("%d %d", &a, &b);
                update(a, -b);
            }else{
                break;
            }
        }

    }
    return 0;
}