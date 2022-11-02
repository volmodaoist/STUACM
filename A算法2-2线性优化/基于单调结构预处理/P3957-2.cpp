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
#define  MAXN  500005

ill dp[MAXN];
int deq[MAXN], head, tail = -1;
int x[MAXN], s[MAXN], n, d, k;


// Ѱ�ҵ�һ�����е�״̬���� now ָ���¼����ʱ����Ҫ x[i] - x[now] < lo,
// ��Щ���ù�����״̬�ᱻ���������º���״̬����������ᵼ�º����һЩ״̬�޷�������!
bool check(int  lo, int hi) {
    dp[0] = 0LL; head = 0, tail = -1;
    for (int i = 1; i <= n; i++){
        dp[i] = -1e18;
    }
    int now = 0;
    for (int i = 1; i <= n; i++) {

        while(now < i && x[i] - x[now] > hi) now++;
        while(head<=tail && x[i] - x[deq[head]] > hi){
            head++;
        }
        // �ҵ���һ������״̬֮��������� [x[i] - hi, x[i] - lo]��״̬�ĺϷ����������ѭ����������֤��
        while (now < i && lo <= x[i] - x[now] && x[i] - x[now] <= hi) {
            while(head<=tail && dp[deq[tail]] <= dp[now]){
                tail--;
            }
            deq[++tail] = now;
            now++;
        }
        if(head <= tail){
            dp[i] = dp[deq[head]] + s[i];
        }
        if (dp[i] >= k)  return true;
    }
    return false;
}

int main(){
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    ill tot = 0;
    cin >> n >> d >> k;
    for (ill i = 1; i <= n; i++) {
        cin >> x[i] >> s[i];
        tot += (s[i] > 0 ? s[i] : 0);
    }

    if(tot < k){
        printf("-1\n");
    } else {
        int lo = 1, hi = x[n];
        while (lo < hi) {
            int md = lo + (hi - lo) / 2;
            if (check(max(1, d - md), d + md)) {
                hi = md;
            } else {
                lo = md + 1;
            }
        }
        printf("%d\n", lo);
    }
    return 0;
} 