#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    unsigned int x;
    scanf("%u", &x);
    printf("%u\n", (x >> 16) | (x << 16));

    return 0;
}