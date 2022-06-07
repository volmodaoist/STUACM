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

// int dx[12] = {-1, +1, -1, +1, -2, +2, -2, +2, -2, -2, +2 + 2};
// int dy[12] = {+2, +2, -2, -2, -1, -1, +1, +1, -2, +2, -2, +2};
int vist[105][105];
int dir[12][2] = {
    {+2, +1}, {+2, +2}, {+1, +2},
    {-1, +2}, {-2, +2}, {-2, +1},
    {-2, -1}, {-2, -2}, {-1, -2},
    {+1, -2}, {+2, -2}, {+2, -1}
};

int bfs(int x, int y){
    memset(vist, 0, sizeof(vist));
    vist[x][y] = 1;

    queue<ii> que;
    que.push({x, y});

    int ans = -1, ansIsFound = 0;
    while(!que.empty()){
        int length = que.size();
        ans++;
        while (length--){
            auto point = que.front(); que.pop();
            int cx = point.xx;
            int cy = point.yy;
            if (cx == 1 && cy == 1){
                ansIsFound = 1; 
                break;
            }
            for (int i = 0; i < 12; i++){
                int nx = cx + dir[i][0];
                int ny = cy + dir[i][1];
                if (nx >= 0 && nx <= 100 && ny >= 0 && ny <= 100 && !vist[nx][ny]){
                    vist[nx][ny] = 1;
                    que.push({nx, ny});
                }
            }
        }
        if(ansIsFound)break;
    }
    return ans;
}


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

    int x, y;
    while (cin >> x >> y){
        cout << bfs(x, y) << endl;

    }
    return 0;
}