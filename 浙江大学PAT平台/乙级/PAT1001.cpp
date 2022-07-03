#include<bits/stdc++.h>
using namespace std;
typedef long long LLong;

LLong x;
int main(){
    while(cin >> x){
        int cnt = 0;
        while(x != 1){
            if(x & 1){
                x = (3 * x + 1) / 2;
            }else{
                x /= 2;
            }
            cnt += 1;
        }
        cout << cnt << endl;
    }
    return 0;
}