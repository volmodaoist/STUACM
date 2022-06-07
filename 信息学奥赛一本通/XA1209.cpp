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

string s;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int n;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    #ifndef  _OJ_ONLINE_JUDGE_
    std::ios::sync_with_stdio(false);
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);//
    #endif

    while (cin >> n){
        queue<int> p;
        queue<int> q;
        for (int i = 0; i < n; i++){
            cin >> s;
            int slash = s.find("/");
            p.push(atoi(s.substr(0, slash).c_str()));
            q.push(atoi(s.substr(slash + 1).c_str()));
        }
        int a, b, c, d;
        int x, y, z;
        while(p.size() > 1){
            // 分数a/b
            a = p.front(); p.pop();
            b = q.front(); q.pop();
            // cout << a << "/" << b << endl;
            
            // 分数c/d
            c = p.front(); p.pop();
            d = q.front(); q.pop();
            // cout << c << "/" << d << endl;

            // a/b 与 c/d 运算
            x = a * d + b * c;
            y = b * d;
            // cout << x << "/" << y << endl;
            

            // 除掉最大公因数
            z = gcd(x, y);

            p.push(x / z);
            q.push(y / z);
        }
        if (q.front() != 1){
            cout << p.front() << "/" << q.front() << endl;
        }else{
            cout << p.front() << endl;
        }
    }

    return 0;
}