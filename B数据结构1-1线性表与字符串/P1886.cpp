#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  MAXN  3000005

int v[MAXN], q[MAXN], n, k, head, tail;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    head = 0, tail = -1;
    for (int i = 0; i < n; i++){
        if(head <= tail && i - q[head] + 1 > k){
            ++head;
        }
        while(head <= tail && v[q[tail]] > v[i]){
            --tail;
        }
        q[++tail] = i;
        if(i - k + 1 >= 0) printf("%d ", v[q[head]]);
    }
    printf("\n");

    head = 0, tail = -1;
    for (int i = 0; i < n; i++) {
        if(head <= tail && i - q[head] + 1 > k){
            ++head;
        }
        while(head <= tail && v[q[tail]] < v[i]){
            --tail;
        }
        q[++tail] = i;
        if(i - k + 1 >= 0) printf("%d ", v[q[head]]);
    }
    printf("\n");

    return 0;
}