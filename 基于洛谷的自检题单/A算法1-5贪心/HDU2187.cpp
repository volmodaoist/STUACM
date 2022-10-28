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

#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  MAXN  100005


typedef struct _Rice{
    int p, h;
    bool operator<(const struct _Rice &other) const{
        return p < other.p;
    }
} Rice;

Rice rices[MAXN];

int kase;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, m, p, h;
    cin >> kase;
    while(kase--){
        cin >> m >> n;
        for (int i = 0; i < n; i++){
            cin >> p >> h;
            rices[i] = {p, h};
        }
        
        // 需要留意题目给出的 p 单价，也即一个单位大米的价格
        sort(rices, rices + n);
        double ans = 0, one = 1.0;
        for (int i = 0; i < n; i++) {
            if(m >= rices[i].p * rices[i].h){
                ans += rices[i].h;
                m -= rices[i].p * rices[i].h;
            } else {
                ans += one * m / (rices[i].h * rices[i].p) * rices[i].h;
                m = 0;
                break;
            }
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}