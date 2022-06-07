#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	min4(x,y,u,v)	(min(min(x,y),min(u,v)))
#define	max4(x,y,u,v)	(max(max(x,y),max(u,v)))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  inserter(x, x.begin())
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <iomanip>
using namespace std;


typedef long long Long;
typedef unsigned long long ULL;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii>  vii;
#define  xx    first
#define  yy    second

string intPrint(int x){
    switch (x){
        case 2: return "2";
        case 1: return "2(0)";
        case 0: return "0";
        default:
            string ans;
            bool head = true;
            for (int i = (sizeof(int) * 8) - 1; i >= 0; i--) {
                if (x & (1 << i)){
                    if(!head){
                        ans += "+";
                    }

                    switch (i){
                        case 1: ans+="2";
                            break;
                        case 0: ans+="2(0)";
                            break;
                        // 此处两个case才是本题的难点, x = 1 or 2, 以及 i(指数部分) 等于 1 or 2,
                        // 递归起来处理方式是不一样的!, 如果使用了intPrint(...), 上面两个case便会出错!

                        default:
                            ans += "2";
                            ans += ("(" + intPrint(i) + ")");
                        // 由于循环变量是高位向递归自减的, 所以default部分先被执行, 经过第一遍switch之后, head已被置为false, 
                        // 因而往后的循环会因此开始填充"+", 若把加号填充的语句放在switch(i){...}之后, 加号位置会于两个操作数之后!
                    }
                    
                    head = false;

                }
            }
            return ans;
    }
}

int kase, x;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    #ifndef  _OJ_ONLINE_JUDGE_
    std::ios::sync_with_stdio(false);
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);//
    #endif

    while (cin >> x){
        cout << intPrint(x) << endl;
    }
    return 0;
}