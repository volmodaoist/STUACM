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


typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii>  vii;
#define  xx    first
#define  yy    second

int cnt[105];
int notPrime[105];

void initPrime(){
    for (int i = 3; i <= 100; i++){
        for (int j = 2; j < i; j++){
            if (i % j == 0){
                notPrime[i] = 1;
                break;
            }
        }
    }
}

void dfs(int x){
    for (int i = 2; i <= x; i++){
        if(!notPrime[i] && (x % i == 0)){
            cnt[i]++;
            dfs(x / i);
            break;
        }
    }
}


int kase, x;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    #ifndef  _OJ_ONLINE_JUDGE_
    std::ios::sync_with_stdio(false);
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);//
    #endif

    initPrime();
    while (cin >> x){
        // 初始化条件
        bool first = true;
        memset(cnt, 0, sizeof(cnt));
        
        // 递归计算指数项
        dfs(x);
        
        // 打印答案
        for (int i = 2; i <= x; i++){
            if(cnt[i]){
                cout << (first ?  string() : string("*")) << i;
                if(cnt[i] > 1){
                    cout << "^" << cnt[i];
                }
                first = false;
            }
        }
        cout << endl;
    }

    return 0;
}