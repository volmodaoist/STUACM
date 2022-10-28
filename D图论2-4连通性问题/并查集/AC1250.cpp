#include <bits/stdc++.h>
#include <limits>
using namespace std;

#define  MAXN  100005

int id;
int mapping(map<int, int>& hash, int x, int y) {
    int p = x * 1000 + y;
    if (!hash.count(p)) {
        hash[p] = ++id;
    }
    return hash[p];
}

int pt[MAXN];
int find(int x){
    return x != pt[x] ? pt[x] = find(pt[x]) : x;
}

int merge(int x, int y){
    int xr = find(x), yr = find(y);
    if(xr != yr){
        pt[xr] = pt[yr];
        return 1;
    }
    return 0;
}


string op;
int n, m, x, y, nx, ny;

int main(){     
    cin >> n >> m;
    map<int, int> hash;
    for (int i = 1; i <= 2 * m; i++)
        pt[i] = i;

    int done = -1;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> op;
        if(op == "D"){
            nx = x + 1, ny = y;
        } else if(op == "R"){
            nx = x, ny = y + 1;
        }
        int p1 = mapping(hash, x, y);
        int p2 = mapping(hash, nx, ny);
        // cout <<"p1 = " << p1 << endl;
        // cout <<"p2 = " << p2 << endl;
        if(find(p1) == find(p2)){
            done = i;
            break;
        }
        merge(p1, p2);
    }

    if (done != -1) {
        cout << done << endl;
    } else {
        cout << "draw" << endl;
    }

    return 0;
}