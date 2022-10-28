#include<bits/stdc++.h>
using namespace std;

typedef long long LLong;

LLong quick_power(LLong a, LLong b, LLong p){
    LLong ans = 1;
    while(b){
        if(b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

int kase;
LLong a, b, p;
int main(){
    cin >> kase;
    while(kase--){
        cin >> a >> b >> p;
        cout << quick_power(a, b, p) << endl;
    }
}