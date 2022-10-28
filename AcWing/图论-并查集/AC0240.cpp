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


typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  fi    first
#define  se    second
#define  MAXN  100005

int p[MAXN], d[MAXN];
int find(int x){
    if (x != p[x]){
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int n, k, op, a, b;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++){
        p[i] = i, d[i] = 0;
    }
    // 0代表同类， 1代表能进食对方，2代表被对方进食
    int ans = 0;
    for (int i = 0; i < k; i++){
        scanf("%d %d %d", &op, &a, &b);
        if(a > n || b > n){
            ans++;
        }else{
            // a和b都在同一个集合里面(已经发生关系)才能比较，否则无法比较
            int ar = find(a), br = find(b);
            if(op == 1){
                if(ar == br && (d[b] - d[a]) % 3){
                    ans++;
                }else if(ar != br){
                    p[ar] = br;
                    d[ar] = d[b] - d[a];
                }
            }else{
                if(ar == br && (d[a] - d[b] - 1) % 3){
                    ans++;
                }else if(ar !=br){
                    p[ar] = br;
                    d[ar] = d[b] - d[a] + 1;
                }
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}