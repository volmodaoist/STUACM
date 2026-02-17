#include <bits/stdc++.h>
#include <limits.h>

using namespace std;

typedef pair<int, int > ii;
vector<ii> intervals;

int n, a, b;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        intervals.push_back({b, a});
    }
    sort(intervals.begin(), intervals.end());
    
    int pts = intervals[0].first, ans = 1;
    for(int i = 1; i < intervals.size(); i++){
        int b = intervals[i].first, a = intervals[i].second;
        if(a <= pts && pts <= b){
            continue;
        }
        ans++, pts = b;
    }
    printf("%d\n", ans);
    return 0;
}