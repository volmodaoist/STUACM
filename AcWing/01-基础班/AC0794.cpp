#include<bits/stdc++.h>
using namespace std;

int ax[100005],b;
int cx[100005];

int div(string &x, int b, int &r){
    int  cnt = 0;
    for(int i = 0; i < x.size(); i++){
        cx[cnt++] = (r * 10 + ax[i]) / b;
        r = (r * 10 + ax[i]) % b;
    }
    // 除法的前导零都在前面需要先倒转再剔除
    reverse(cx, cx + cnt);
    while(cnt > 0 && cx[cnt] == 0) cnt--;
    return cnt;
}

int main(){
    string x;
    while(cin>>x>>b){
        // 除法是从高位到低位顺序处理的
        for(int i = 0; i < x.size(); i++){
            ax[i] = x[i] - '0';
        }
        int r = 0;
        int cnt = div(x, b, r);
        for(int i  = cnt; i >= 0; i--){
            printf("%d", cx[i]);
        }
        printf("\n%d\n", r);
    }
    return 0;
}