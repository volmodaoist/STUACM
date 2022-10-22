#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


// https://codeforces.com/problemset/problem/71/A
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n;
    char str[150];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", str);
        int len = strlen(str);
        if(len <= 10){
            printf("%s\n", str);
        }else{
            printf("%c%d%c\n", str[0], len - 2, str[len - 1]);
        }
    }
    return 0;
}