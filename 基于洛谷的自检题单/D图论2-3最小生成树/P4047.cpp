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


typedef long long ill;
typedef unsigned long long ull;
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
    int a, b;
    double w;
} Egde;

Point p[MAXN];
vector<Edge> edges;
int n, k, a, b, ft[MAXN];

int find(int x){
    return ft[x] != x ? (ft[x] = find(ft[x])) : x;
}
void debug_print_edges(){
    // debug打印看看连边是不是计算出错了
    for (int i = 0; i < edges.size(); i++){
        printf("e(%d, %d) = %.2f\n", edges[i].a, edges[i].b, edges[i].w);
    }
}

double dist(Point &a, Point &b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double kruskal(){
    double mst = 0, ans = 0;
    for (int i = 0; i < n; i++)
        ft[i] = i;
    
    // debug_print_edges();
    sort(edges.begin(), edges.end(),[](const Edge& a, const Edge& b) { 
        return a.w < b.w; 
    });


    int cnt = 0;
    bool now_k_groups = false;
    for (int i = 0; i < edges.size(); i++) {
        int ar = find(edges[i].a), br = find(edges[i].b);
        if (ar != br){
            ft[ar] = ft[br];
            mst += edges[i].w;
            ans = edges[i].w;
            cnt += 1;
            if(now_k_groups) break;
        }
        if(cnt == n - k) now_k_groups = true;
    }
    return ans;
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        p[i] = {a, b};
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            edges.push_back({i, j, dist(p[i], p[j])});
        }
    }
    printf("%.2lf", kruskal());
    return 0;
}