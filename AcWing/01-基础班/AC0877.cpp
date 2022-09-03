#include<bits/stdc++.h>
using namespace std;

int a, b, x, y;
int exgcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    int d  = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int n;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        exgcd(a,b, x, y);
        printf("%d %d\n", x, y);
    }
    return 0;
}