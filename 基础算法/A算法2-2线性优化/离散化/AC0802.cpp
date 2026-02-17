#include<bits/stdc++.h>
using namespace std;

int n, m, l, r, x, c, p;
vector<pair<int, int>> inc;
vector<pair<int, int>> que;
vector<int> points;

int binary_search(int t){
    int lo = 0, hi = points.size() - 1;
    while(lo < hi){
        int md = lo + (hi - lo) / 2;
        if(points[md] >= t){
            hi = md;
        }else{
            lo = md + 1;
        }
    }
    return lo + 1; 
}

int arr[300030];

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &x, &c);
        inc.push_back({x,c});
        points.push_back(x);            
    }
    for(int i = 0; i < m; i++){
        scanf("%d %d",&l, &r);
        que.push_back({l, r});
        points.push_back(l);
        points.push_back(r);
    }
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());
    for(int i = 0; i < inc.size(); i++){
        x = binary_search(inc[i].first);
        c = inc[i].second;
        arr[x] += c;
    }
    for(int i = 1; i <= points.size(); i++){
      arr[i] = arr[i - 1] + arr[i];
    }
    for(int i = 0; i < que.size(); i++){
        l = binary_search(que[i].first);
        r = binary_search(que[i].second);
        printf("%d\n", arr[r] - arr[l - 1]);

    }
    return 0;
}