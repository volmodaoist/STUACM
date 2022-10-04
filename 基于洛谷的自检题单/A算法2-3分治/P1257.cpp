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
#include <limits.h>
using namespace std;


typedef long long llong;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
#define  MAXN  100005

typedef struct _Point{
    double x, y;
} Point;

Point points[MAXN];
int tmp[MAXN];

double dist(int i, int j){
    double x1 = points[i].x, y1 = points[i].y;
    double x2 = points[j].x, y2 = points[j].y;
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double merge(int lo, int hi){
    double d = 1e9;
    if (lo == hi)
        return d;
    
    if(lo + 1 == hi)
        return dist(lo, hi);

    int md = lo + (hi - lo) / 2;
    double d1 = merge(lo, md);
    double d2 = merge(md + 1, hi);
    d = min(d1, d2);
    

    // 找出中间 [p[md].x - dis, p[md].x + dis] 这个区域的坐标
    // 因为最短距离有可能出现于跨左右两个子段的区域，也即一个顶点在左一个顶点在右
    int k = 0;
    for (int i = lo; i <= hi; i++){
        if(fabs(points[i].x - points[md].x) <= d){
            tmp[k++] = i;
        }
    }

    // 我们注意到给定的坐标点均为整数，也即按照x/y排序之后，随着索引变远，点对之间的距离越来越大
    for (int i = 0; i < k; i++){
        // 循环条件 points[tmp[i]].y - points[tmp[j]].y 极大的减少了搜索范围
        for (int j = i + 1; (j < k) && (points[tmp[j]].y - points[tmp[i]].y < d); j++){
            d = min(d, dist(tmp[i], tmp[j]));
        }
    }
    return d;
}

int n;
int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    double x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x, &y);
        points[i] = {x, y};
    }
    sort(points, points + n, [](const struct _Point& p1, const struct _Point &p2){
        if(p1.x != p2.x){
            return p1.x < p2.x;
        }else{
            return p1.y < p2.y;
        }
    });

    printf("%.4lf\n", merge(0, n - 1));

    return 0;
}