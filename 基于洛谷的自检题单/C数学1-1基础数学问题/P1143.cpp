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

int n, m;
string digits;

int c2i(char c){
    if(isdigit(c)){
        return c - '0';
    }else{
        return c - 'A' + 10;
    }
}

char i2c(int x){
    if (0 <= x && x <= 9){
        return '0' + x;
    }else{
        return 'A' + (x % 10);
    }
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    // c2i['1'] = 1, c2i['2'] = 2, c2i['3'] = 3, c2i['4'] = 4, c2i['5'] = 5;
    // c2i['6'] = 6, c2i['7'] = 7, c2i['8'] = 8, c2i['9'] = 9, c2i['0'] = 0;
    // c2i['A'] = 10, c2i['B'] = 11, c2i['C'] = 12, c2i['D'] = 13, c2i['E'] = 14;
    // c2i['F'] = '15';

    cin >> n;
    cin >> digits;
    cin >> m;
    reverse(digits.begin(), digits.end());
    llong tmp = 0, t = 1;
    for (auto i : digits) {
        tmp += c2i(i) * t;
        t = t * n;
    }

    vector<char> ans;
    while(tmp >= m){
        ans.push_back(i2c(tmp % m));
        tmp /= m;
    }
    ans.push_back(i2c(tmp));
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}