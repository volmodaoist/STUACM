#include<bits/stdc++.h>
using namespace std;

#define MAXN 500005
pair<int, int> cows[MAXN];

int n, w, s;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &w, &s);
        cows[i] = {w + s, s};
    }
    sort(cows, cows + n);
    int sumv = 0, ans =  INT_MIN;
    for(int i = 0; i < n; i++){
        int w = cows[i].first - cows[i].second;
        int s = cows[i].second;
        ans = max(ans, sumv - s);
        sumv += w;
    }
    printf("%d\n", ans);
    return 0;
}