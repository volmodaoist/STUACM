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
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
#define  MAXN  100005

int n, m;


void solve(){
    scanf("%d %d", &n, &m);
    ill ans1 = 0, ans2 = 0, sumv = 0;
    // ���ݳ˷�ԭ��m x n����������θ��� n x m�����������θ��� min(m,n)^2
    // ���εĸ������������������������г����Σ���������εĸ�������ͨ������ķ������
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= m; j++){
            ans1 += min(i, j);
            sumv += (i * j);
        }
    }
    printf("%lld %lld\n", ans1, sumv - ans1);
}

int main() {
    solve();
    return 0;
}




void TLE(){
    scanf("%d %d", &n, &m);
    int ans1 = 0, ans2 = 0, r = max(n, m);

    // ö�ٱ߳�����ö������
    for (int k = 0; k <= r; k++){
        for (int i = 1; i <= n; i++) {
            if(i + k > n) break;
            for (int j = 1; j <= m; j++) {
                if(j + k > m) break;
                if (i + k <= n && j + k <= m) {
                    ans1++;
                }
            }
        }
    }
    // ö�ٳ����ı߳�����ö������
    for (int k1 = 0; k1 <= n; k1++){
        for (int k2 = 0; k2 <= m; k2++){
            if(k1 == k2) continue;
            for (int i = 1; i <= n; i++) {
                if(i + k1 > n) break;
                for (int j = 1; j <= m; j++) {
                    if(j + k2 > m) break;
                    if (i + k1 <= n && j + k2 <= m) {
                        ans2++;
                    }
                }
            }
        }
    }
    printf("%d %d\n", ans1, ans2);
}