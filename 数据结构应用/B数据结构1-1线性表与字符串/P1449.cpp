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

char str[MAXN];

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%s", str);
    int num = 0;
    int len = strlen(str);
    stack<int> stk;
    for (int i = 0; i < len; i++) {
        if(isdigit(str[i])){
            num = num * 10 + (str[i] - '0');
        }else if(str[i] == '.'){
            stk.push(num);
            num = 0;
        }else{
            if(str[i] == '@')
                break;
            int y = stk.top();stk.pop();
            int x = stk.top(); stk.pop();
            if(str[i] == '+'){
                stk.push(x + y);
            } else if (str[i] == '-') {
                stk.push(x - y);
            } else if (str[i] == '*') {
                stk.push(x * y);
            } else if (str[i] == '/') {
                stk.push(x / y);
            }
        }
    }
    printf("%d\n", stk.top());
    return 0;
}