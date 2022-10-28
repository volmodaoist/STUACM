#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) ((x)&(-x))
int n, x;
int main(){
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            int cnt = 0;
            while(x){
                cnt++;
                x -= lowbit(x);
            }
            printf("%d%s", cnt, (i == n - 1 ? "\n" : " "));
        }   
    }
    return 0;
}