#include <bits/stdc++.h>
#include <limits.h>
using namespace std;



// https://codeforces.com/contest/732/problem/A
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    int k, r;
    
    scanf("%d %d", &k, &r);
    for (int i = 1; i <= 10; i++) {
        if (i * k % 10 == 0 || i * k % 10 == r){
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}