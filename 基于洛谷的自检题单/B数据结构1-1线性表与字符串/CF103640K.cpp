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
 
 
typedef long long llong;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
#define  MAXN  100005
 

// 拉丁美洲的 ICPC 真题(签到题)
// https://codeforces.com/gym/103640/problem/K

string s;
int n;
int main() {
#ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
 
    while (cin >> n){
        set<char> first_letter;
        vector<string> strs;
        for (int i = 0; i < n; i++) {
            cin >> s;
            strs.push_back(s);
            first_letter.insert(s[0]);
        }
 
        bool fg = true;
        for (auto str: strs){
            fg = true;
            for (int j = 0; j < str.size(); j++) {
                if(!first_letter.count(str[j])){
                    fg = false;
                    break;
                }
            }
            if(fg)break;
        }
        cout << (fg ? "Y" : "N") << endl;
    }
    return 0;
}
