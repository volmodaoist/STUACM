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


// �������������������� https://codeforces.com/gym/103119/problem/L
// �����������һ���������� {ai}��ÿ��Ԫ�ض���1~n, Ҫ���������1~n���ֵ�ȫ����{pi}����������pi<=ai���������
// ����������г�ʽ�� (n! * n!) / (n^n), �ѵ����ڴ����Ĵ���һ�ֱȽ�ȡ�ɵķ�������Python������һ�ַ������� long double ����

int kase;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n;
    long double ans = 1.0;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        ans = (ans * i * i) / n;
    }
    printf("%.15Lf\n", ans);

    return 0;
}