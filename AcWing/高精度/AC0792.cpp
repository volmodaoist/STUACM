#include<bits/stdc++.h>
using namespace std;


string a,b;
int ax[100005], bx[100005], cx[100005];

bool cmp(string &a, string &b){
    if(a.size() != b.size()) 
        return a.size() >= b.size();
    return a >= b;
}

int sub(string &a, string &b){
    for(int i = a.size() - 1; i >= 0; i--) ax[a.size() - 1 - i] = a[i] - '0';
    for(int i = b.size() - 1; i >= 0; i--) bx[b.size() - 1 - i] = b[i] - '0';
    int borrow = 0, cnt = 0;
    for(int i = 0; i < a.size(); i++){
        cx[cnt++] = (ax[i] - bx[i] - borrow + 10) % 10;
        borrow = (ax[i] - bx[i] - borrow < 0);
    }
    
    // 去除前导零
    while(cnt > 0 && cx[cnt] == 0) cnt--;
    return cnt;
}


int main(){
    while(cin >> a >> b){
        if(cmp(a, b)){
            int cnt = sub(a, b);
            for(int i = cnt; i >= 0; i--){
                printf("%d",cx[i]);
            }
        }else{
            int cnt= sub(b, a);
            printf("-");
            for(int i = cnt; i >= 0; i--){
                printf("%d",cx[i]);
            }
        }
        printf("\n");
    }
    return 0;
}