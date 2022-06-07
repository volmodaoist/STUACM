#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long Long;

Long n, c;
Long pos[100005];

bool check(Long x){
    Long cnt = 1;
    Long tmp = pos[0] + x;

    for (int i = 1; i < n; i++){
        if(pos[i] >= tmp){
            cnt++;
            tmp = pos[i] + x;
        }
    }
    return cnt >= c;
}

Long binarySearch(Long lo, Long hi){
    Long md;
    while(lo <= hi){
        md = lo + (hi - lo) / 2;
        if(check(md)){
            lo = md + 1;
        }else{
            hi = md - 1;
        }
    }
    return hi;
}

int main(){
    scanf("%lld %lld", &n, &c);
    for (int i = 0; i < n; i++){
        scanf("%lld", &pos[i]);
    }
    sort(pos, pos + n);
    printf("%d\n", binarySearch(1, pos[n - 1] - pos[0]));
    return 0;
}