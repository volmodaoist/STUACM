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

int a, b, c, g, n;
int vis[10], path[10], cnt = 0;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

bool check(){
    int A = path[0] * 100 + path[1] * 10 + path[2];
    int B = path[3] * 100 + path[4] * 10 + path[5];
    int C = path[6] * 100 + path[7] * 10 + path[8];
    int G = gcd(gcd(A, B), C);
    int g = gcd(gcd(a, b), c);
    A /= G, B /= G, C /= G, a /= g, b /= g, c /= g;
    return A == a && B == b && C == c;
}

void dfs(int x){
    if (x == 9){
        if(check()){
            cnt++;
            for (int i = 0; i < 9; i++) {
                printf("%d%s", path[i], ((i + 1) % 3 == 0) ? " " : "");
            }
            printf("\n");
        }
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            path[x] = i;
            dfs(x + 1);
            vis[i] = 0;
        }
    }
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d %d %d", &a, &b, &c);
    dfs(0);
    if (cnt == 0){
        printf("No!!!\n");
    }
    return 0;
}