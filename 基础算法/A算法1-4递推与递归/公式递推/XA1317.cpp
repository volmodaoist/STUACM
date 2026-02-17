#include <bits/stdc++.h>
#include <iomanip>
using namespace std;


typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii>  vii;
#define  xx    first
#define  yy    second

int path[105];
int book[105];
void dfs(int n , int r, int u, int state){
    if (u == r + 1){
        for (int i = 1; i <= r; i++){
            printf("%3d", path[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < n; i++){
        if (!(state & (1 << i))){
            if (i + 1 > path[u - 1]){
                path[u] = i + 1;
                dfs(n, r, u + 1, state | (1 << i));
            }
        }
    }
}


int main(){ 
    int n, r;
    while (cin >> n >> r){
        memset(path, 0, sizeof(path));
        memset(book, 0, sizeof(book));
        dfs(n, r, 1, 0);
    }
    return 0;
}