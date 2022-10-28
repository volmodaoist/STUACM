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


int kase;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d", &kase);
    while(kase--){
        int n, a, b;
        scanf("%d %d %d", &n, &a, &b);
        if(a > b){
            swap(a, b);
        }
        // ����ʤ����ֵܾ���������ȵģ�����Ϊ����ֻ��һ���˻�ʤ���ܾ�����һ������ n - 1
        if (a == 0 && b > 0 && ((n - 1) % b == 0)) {
            // �����ǵ�2���˻�ʤ���ܹ������������2�������Ҫ������
            for (int k = 2; k <= n; k += b) {
                for (int i = 1; i <= b; i++){
                    printf("%d ", k);
                }
            }
            printf("\n");
        } else {
            printf("-1\n");
        }
    }
    return 0;
}