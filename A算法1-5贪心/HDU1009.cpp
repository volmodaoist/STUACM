#include <bits/stdc++.h>
#include <limits>
using namespace std;


#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  MAXN  100005

typedef struct _Room{
    int j, f;
    bool operator<(const struct _Room& other) const{
        double one = 1.000;
        return (one * j / f) > (one * other.j / other.f);
    }
} Room;

int n, m;
Room rooms[MAXN];

int main() {
    while (scanf("%d %d", &m, &n)) {
        if(m == -1 && n == -1)
            break;
            
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &rooms[i].j, &rooms[i].f);
        }

        // 按照性价比排序是一个非常直观的想法
        sort(rooms, rooms + n);

        // 需要注意此处的浮点精度控制，如果不乘以 one 会导致精度出错
        double ans = 0, one = 1.0000;
        for (int i = 0; i < n; i++) {
            if(m >= rooms[i].f){
                ans += rooms[i].j;
                m -= rooms[i].f;
            } else {
                ans += (one * rooms[i].j / rooms[i].f * m);
                m = 0;
                break;
            }
        }
        printf("%.3lf\n", ans);
    }

    return 0;
}