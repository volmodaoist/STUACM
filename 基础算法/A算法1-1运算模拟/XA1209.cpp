#include <bits/stdc++.h>
#include <iomanip>
using namespace std;



string s;
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    int n, a, b, c, d, x, y, z;
    while (cin >> n) {
        queue<int> p;
        queue<int> q;
        for (int i = 0; i < n; i++){
            cin >> s;
            int slash = s.find("/");
            p.push(atoi(s.substr(0, slash).c_str()));
            q.push(atoi(s.substr(slash + 1).c_str()));
        }
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