#include<bits/stdc++.h>
using namespace std;

int m, x;
int stk[100005], top;

int main(){
    while(cin>>m){
        string op;
        for(int i = 0; i < m; i++){
            cin >> op;
            if(op == "push"){
                cin >> x;
                stk[++top] = x;
            }else if(op == "pop"){
                stk[top--];
            }else if(op == "empty"){
                cout << ((top == 0) ? "YES":"NO") << endl;
            }else if(op == "query"){
                cout << stk[top] << endl;
            }
        }
    }
    return 0;
}