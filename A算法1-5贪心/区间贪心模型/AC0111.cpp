#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
typedef struct range{
    int lo, hi;
    int id;
    bool operator<(struct range &other) const{
        return lo < other.lo;
    }
}Range;

typedef pair<int, int> ii;

Range cows[MAXN];
int n, a, b, ans[MAXN];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        cows[i] = {a, b, i};
    }
    sort(cows, cows + n);
    priority_queue<ii, vector<ii>, greater<ii>> heap;
    
    for(int i = 0; i < n; i++){
        if(heap.empty() || heap.top().first >= cows[i].lo){
            ans[cows[i].id] = heap.size();
            heap.push({cows[i].hi, heap.size()});        // 牛栏为空或必有交集的时候新开一个
        }else{
            auto tmp = heap.top(); heap.pop();           // 没有交集的时候的选择结束时间最早的一个出栏
            ans[cows[i].id] = tmp.second;
            heap.push({cows[i].hi, tmp.second});
        }
    }
    printf("%d\n", heap.size());
    for(int i = 0; i < n; i++){
        printf("%d\n", ans[i] + 1);
    }
    return 0;
}