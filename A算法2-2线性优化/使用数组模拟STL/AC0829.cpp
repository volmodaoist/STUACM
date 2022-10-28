#include<bits/stdc++.h>
using namespace std;

int m, x;
int que[100005], head, tail;

int main(){
    string op;
    while(cin>>m){
        head = tail = 0;
        for(int i = 0; i < m; i++){
            cin >> op;
            if(op == "push"){
                cin >> x;
                que[tail++] = x; 
            }else if(op == "pop"){
                que[head++];
            }else if(op == "empty"){
                cout << ((head == tail) ? "YES" : "NO") << endl;
            }else if(op == "query"){
                cout << que[head] << endl;
            }
        }
    }    
}