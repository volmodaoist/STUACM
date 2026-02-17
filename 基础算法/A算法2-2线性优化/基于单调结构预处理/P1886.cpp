#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
#define  MAXN  6000005

int n, k;
int deq[MAXN], head, tail = -1;
int arr[MAXN], wmin[MAXN], wmax[MAXN], len = 0;

int main(){ 
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for (int i = 0, head = 0, tail = -1; i < n; i++){
        while (head <= tail && i - deq[head] + 1 > k) {
            head++;
        }
        while(head<=tail && arr[i] < arr[deq[tail]]){
            tail--;
        }
        deq[++tail] = i;
        if(i >= k - 1){
            printf("%d ", arr[deq[head]]);
        }
    }
    printf("\n");

    for (int i = 0, head = 0, tail = -1; i < n; i++){
        while (head <= tail && i - deq[head] + 1 > k) {
            head++;
        }
        while(head<=tail && arr[i] > arr[deq[tail]]){
            tail--;
        }
        deq[++tail] = i;
        if(i >= k - 1){
            printf("%d ", arr[deq[head]]);
        }
    }
    printf("\n");

    return 0;
}