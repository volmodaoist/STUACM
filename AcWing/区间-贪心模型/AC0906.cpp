#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
typedef struct range{
    int lo, hi;
    bool operator <(const struct range & other){
        return lo < other.lo;
    }
}Range;

Range ranges[MAXN];

int n, a, b;
int main(){
    scanf("%d", &n);
    priority_queue<int, vector<int>, greater<int>> heap;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        ranges[i] = {a, b};
    }
    sort(ranges, ranges + n);
    for(int i = 0; i < n; i++){
        if(heap.empty() || heap.top() >= ranges[i].lo){
            heap.push(ranges[i].hi);
        }else{
            heap.pop();
            heap.push(ranges[i].hi);
        }

    }
    printf("%d\n", heap.size());
    return 0;
}