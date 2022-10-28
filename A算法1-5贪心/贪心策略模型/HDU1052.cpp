#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	CLEAR(A,x)  (memset(A,x,sizeof(A)))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <limits>
using namespace std;

#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  MAXN  100005

int ji[MAXN], qi[MAXN], n;

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    while(scanf("%d", &n) && n){
        for (int i = 0; i < n; i++)
            scanf("%d", &ji[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &qi[i]);
        sort(ji, ji + n);
        sort(qi, qi + n);

        int ji_lo = 0, ji_hi = n - 1;
        int qi_lo = 0, qi_hi = n - 1;
        int money = 0;

        // 马数量 n，因而总共需要比较 n 回合，此处 for 循环只用于控制比较次数，循环变量 i 是不作为的!
        for (int i = 0; i < n; i++) {
            if(ji[ji_lo] > qi[qi_lo]){
                // 如果田忌下马快于齐王下马则赢下这个回合
                money += 200;
                ji_lo++; // 田忌使用下马
                qi_lo++; // 齐王使用下马
            } else if (ji[ji_lo] < qi[qi_lo]) {
                // 如果田忌下马的速度比齐王的要慢，那么反正都要输，则应使其对战齐王的上马
                money -= 200;
                ji_lo++; // 田忌使用下马
                qi_hi--; // 齐王使用上马
            }else if(ji[ji_lo] == qi[qi_lo]){
                // 如果下马的速度相等，要慢选择打平，要么选择使用下马耗掉齐王上马，此时需要根据上马的速度分类讨论
                if(ji[ji_hi] > qi[qi_hi]){ // 如果田忌上马更快，能赢齐王上马，则让上马对战上马
                    money += 200;
                    ji_hi--; // 田忌使用上马
                    qi_hi--; // 齐王使用上马
                }else{ // 如果田忌的上马赢不了齐王的上马，则让下马耗掉齐王的上马，留着田忌上马，将来用于对付齐王的中马
                    if(ji[ji_lo] < qi[qi_hi]){ // 随着田忌下马、齐王上马的消耗，中间的马匹有可能出现平局
                        money -= 200;
                    }
                    ji_lo++; // 田忌使用了下马
                    qi_hi--; // 齐王使用了上马
                }
            }
        }
        printf("%d\n", money);
    }
    return 0;
}