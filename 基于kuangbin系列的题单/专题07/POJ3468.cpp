#define _OJ_ONLINE_JUDGE_

#include <stdio.h>
#include <algorithm>
using namespace std;

#define  MAXN  200010

inline int lowbit(int x){
    return -x & x;
}

int a, b, c, n, m;
int ar[MAXN], tr[MAXN];

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    while (scanf("%d %d", &n, &m) != EOF){
        for (int i = 1; i <= n; i++){
            scanf("%d", &ar[i]);
        } 
    
    }

    return 0;
}