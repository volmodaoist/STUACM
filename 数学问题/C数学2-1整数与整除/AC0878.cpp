#include<bits/stdc++.h>
using namespace std;

typedef long long LLong;
int exgcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a%b, y, x);
    y -= (a / b) *x;
    return d;
}

int n, a, b, x, y, m;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &a, &b, &m);
        int d = exgcd(a, m, x, y);
        if(b % d){
            printf("impossible\n");
        }else{
            printf("%d\n", (LLong)x * (b / d) % m);   
        }
    }
    return 0;
}