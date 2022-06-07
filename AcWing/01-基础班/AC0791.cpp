#include<bits/stdc++.h>
using namespace std;

string a,b;
int ax[100005], bx[100005], cx[100005];


int main(){
    while(cin >> a >> b){
        for(int i = a.size() - 1; i >= 0; i--){ax[a.size() - 1 - i] = a[i] - '0';}
        for(int i = b.size() - 1; i >= 0; i--){bx[b.size() - 1 - i] = b[i] - '0';}
        
        int len = max(a.size(), b.size());
        int carry = 0;
        
        for(int i = 0; i < len; i++){
            cx[i] = (ax[i] + bx[i] + carry) % 10;
            carry = (ax[i] + bx[i] + carry) / 10;
        }
        
        if(carry) cx[len++] = 1;
        for(int i = len - 1; i >= 0; i--){
            printf("%d",cx[i]);
        }
        printf("\n");
    }
    return 0;
}