#include<bits/stdc++.h>
using namespace std;

int n, x;
int main(){
    priority_queue<int, vector<int>, greater<int>> heap;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        heap.push(x);
    }
    int ans = 0;
    while(heap.size() > 1){
        int a = heap.top(); heap.pop();
        int b = heap.top(); heap.pop();
        ans += (a + b);
        heap.push(a + b);
    }
    printf("%d\n", ans); // 只有一堆的时候无需合并，不消耗体力
    return 0;
}