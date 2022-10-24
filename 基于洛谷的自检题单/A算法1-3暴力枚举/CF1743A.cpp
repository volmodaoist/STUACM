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


int kase, n, x, not_in[10], cot[10];
bool check(int i, int j, int k, int h){
    int cnt = 0;
    memset(cot, 0, sizeof(cot));
    cot[i]++, cot[j]++, cot[k]++, cot[h]++;
    // printf("%d %d %d %d\n", i, j, k, h);
    // printf("%d %d %d %d\n", cot[i], cot[j], cot[k], cot[h]);
    for (int i = 0; i < 10; i++) {
        if (cot[i] != 0){
            cnt++;
            if (cot[i] != 2) {
                return false;
            }
        }
    }
    return cnt == 2;
}


int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d", &kase);
    while(kase--){
        scanf("%d", &n);
        memset(not_in, 0, sizeof(not_in));
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            not_in[x] = 1;
        }
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            if(not_in[i])continue;
            for (int j = 0; j < 10; j++) {
                if(not_in[j])continue;
                for (int k = 0; k < 10; k++){
                    if(not_in[k])continue;
                    for (int h = 0; h < 10; h++){
                        if(not_in[h])continue;
                        if (check(i, j, k, h)) {
                            ans++;
                        }
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}