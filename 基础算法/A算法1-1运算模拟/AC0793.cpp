#include<bits/stdc++.h>
using namespace std;

int ax[100005], cx[100005], n, b;

int mul(string &x, int b){
    int carry = 0, cnt = 0;
    for(int i = 0; i < x.size(); i++){
        cx[cnt++] =  (ax[i] * b + carry) % 10;
        carry = (ax[i] * b + carry) / 10;
    }
    //去掉前导零
    while(carry){
        cx[cnt++] =  carry % 10;
        carry /= 10;
    }
    while(cnt > 0 && cx[cnt] == 0) cnt--;
    return cnt;
}

int main(){
    string x;
    while(cin >> x >> b){
        for(int i = x.size() - 1; i >= 0; i--){
            ax[x.size() - 1 - i] = (x[i] - '0');
        }
        int cnt = mul(x, b);
        for(int i = cnt;  i >= 0; i--){
            printf("%d", cx[i]);
        }
        printf("\n");
    }
    return 0;
}