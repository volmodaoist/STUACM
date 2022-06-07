#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	min4(x,y,u,v)	(min(min(x,y),min(u,v)))
#define	max4(x,y,u,v)	(max(max(x,y),max(u,v)))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  inserter(x, x.begin())
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <iomanip>


using namespace std;


typedef long long Long;
typedef unsigned long long ULL;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii>  vii;
#define  xx    first
#define  yy    second

int kase;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    #ifndef  _OJ_ONLINE_JUDGE_
    std::ios::sync_with_stdio(false);
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);//
    #endif

    double a, b, c;
    while (scanf("%lf %lf %lf", &a, &b, &c) != EOF){
        double delta = b * b - 4 * a * c;
        if(delta < 0 && abs(delta) > EPS){
            printf("No answer!\n");
        }else if (abs(delta) < EPS){
            double ans = (-b) / (2 * a);
            if(abs(ans) < EPS){
                printf("x1=x2=%.5lf\n", 0);
            }else{
                printf("x1=x2=%.5lf\n", ans);
            }
        }else{
            double x1 = (-b - sqrt(delta)) / (2 * a);
            double x2 = (-b + sqrt(delta)) / (2 * a);
            if(x1 > x2){
                swap(x1, x2);
            }
            printf("x1=%.5lf;x2=%.5lf\n", x1, x2);
        }
    }

    return 0;
}