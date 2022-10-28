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
#define  MAXN  3000005


int n;
ill nums[MAXN];
ill f[MAXN], g[MAXN];
ill p[MAXN], q[MAXN], total;

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    // ά�������Ӷκͣ�һ������A[i]��β������Ӷκͣ���һ������A[i]��ͷ������Ӷκ�
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &nums[i]);
        total += nums[i];
    }

    f[1] = nums[1];
    for (int i = 2; i <= n; i++){
        f[i] = max(f[i - 1] + nums[i], nums[i]);
    }
    for (int i = 2; i <= n; i++) {
        f[i] = max(f[i - 1], f[i]);
    }

    g[n] = nums[n];
    for (int i = n - 1; i > 0; i--) {
        g[i] = max(g[i + 1] + nums[i], nums[i]);
    }
    for (int i = n - 1; i > 0; i--){
        g[i] = max(g[i + 1], g[i]);
    }

    ill maxv = INT_MIN;
    for (int i = 1; i < n; i++) {
        maxv = max(maxv, f[i] + g[i + 1]);
    }


    // ά�������Ӷκͣ�һ������A[i]��β����С�Ӷκͣ���һ������A[i]��ͷ����С�Ӷκ�
    memset(p, 0x3f, sizeof(p));
    memset(q, 0x3f, sizeof(q));
    p[1] = nums[1];
    for (int i = 2; i <= n; i++) {
        p[i] = min(p[i - 1] + nums[i], nums[i]);
    }
    for (int i = 2; i <= n; i++) {
        p[i] = min(p[i - 1], p[i]);
    }

    q[n] = nums[n];
    for (int i = n - 1; i > 0; i--) {
        q[i] = min(q[i + 1] + nums[i], nums[i]);
    }
    for (int i = n - 1; i > 0; i--) {
        q[i] = min(q[i + 1], q[i]);
    }

    ill minv = INT_MAX;
    for (int i = 1; i < n; i++) {
        minv = min(minv, p[i] + q[i + 1]);
    }
    
    // ��ʵ������С�Ӷκͼ�ʹ���Ҳû�й�ϵ��ֻҪ����������С�Ӷ�֮��ǡ�õ����ܺ͵������
    // ��� minv == total, ˵������ȫΪ��������СֵӦΪ���ֵ��δ�ֵ֮�ͣ����� total-sumv ������㵼�´���
    
    ill ans = INT_MIN;
    if (minv != total) {
        ans = max(maxv, total - minv);
    }else{
        ans = maxv;
    }
    printf("%lld\n", ans);

    return 0;
}