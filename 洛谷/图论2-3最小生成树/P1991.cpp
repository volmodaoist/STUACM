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


typedef long long LLong;
typedef unsigned long long ULL;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
#define  fi    first
#define  se    second
#define  MAXN  100005

typedef struct Point{
    int x, y;
} Point;

typedef struct Edge{
    int x, y;
    double w;
} Edge;

Point p[MAXN];
vector<Edge> edges;

int s, n, a, b, pt[MAXN];

int find(int x){
    return x != pt[x] ? (pt[x] = find(pt[x])) : x;
}

void merge(int x, int y){
    int xr = find(x), yr = find(y);
    if(xr != yr){
        pt[xr] = pt[yr];
    }
}

double dist(Point &a, Point &b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double kruskal(int s, int n){
   // 初始化并查集
   int cnt = 0;
   double cost = 0, ans = 0;
   for (int i = 1; i <= n; i++)
       pt[i] = i;
   for (int i = 0; i < edges.size(); i++) {
        int x = edges[i].x, y = edges[i].y;
        if (find(x) != find(y)) {
            merge(x, y);
            ans = edges[i].w;
            cost += edges[i].w;
            cnt++;
        }
        if(cnt == n - s) break;
   }
   return ans;
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d %d", &s, &n);
    for (int i = 1; i <= n; i++){
        scanf("%d %d", &a, &b);
        p[i] = {a, b};
    }


    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++){
            edges.push_back({i, j, dist(p[i], p[j])});
        }
    }
    
    sort(edges.begin(), edges.end(),
        [](const Edge& a, const Edge& b) { 
            return a.w < b.w;
    });
    double ans = kruskal(s, n);
    printf("%.2lf\n", ans);
    return 0;
}