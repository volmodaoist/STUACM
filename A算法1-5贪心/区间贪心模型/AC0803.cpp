#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> intervals;
vector<pair<int, int>> res;

int n, lo, hi;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d",&lo, &hi);
        intervals.push_back({lo, hi});
    }
    sort(intervals.begin(), intervals.end());
    
    int bg = -2e9, ed = -2e9;
    for(auto interval: intervals){
        lo = interval.first;
        hi = interval.second;
        if(ed < lo){
            if(ed != -2e9){
                res.push_back({bg, ed});
            }
            bg = lo, ed = hi;
        }else if(ed <= hi){
            ed = hi;
        }
    }
    res.push_back({bg, ed});
    
    // for(auto r: res){
    //     printf("[%d,%d]\n", r.first, r.second);
    // }
    
    printf("%d\n",res.size());
    return 0;
}