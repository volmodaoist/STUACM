#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  MAXN  100005


// �������������������� https://codeforces.com/gym/103119/problem/L
// �����������һ���������� {ai}��ÿ��Ԫ�ض���1~n, Ҫ���������1~n���ֵ�ȫ����{pi}����������pi <= ai���������
// ����������г�ʽ�� (n! * n!) / (n^n), �ѵ����ڴ����Ĵ���һ�ֱȽ�ȡ�ɵķ�������Python������һ�ַ������� long double ����



int main(){ 
    int n;
    long double ans = 1.0;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        ans = (ans * i * i) / n;
    }
    printf("%.15Lf\n", ans);

    return 0;
}