#include<bits/stdc++.h>
using namespace std;

int n, x; 
int top, stk[100005];
int main(){
    while(cin >> n){
        for(int i = 0; i < n; i++){
            cin >> x;
            while(top && stk[top] >= x){
                top--;
            }
            cout << (top ? stk[top] : -1) << " ";
            stk[++top] = x;
        }
    }
    return 0;
}