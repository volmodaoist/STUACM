#include<bits/stdc++.h>
using namespace std;

// 滑动窗口模板

int n, k;
int arr[1000005];
int que[1000005], head, tail;
int main(){
    while(cin >> n >> k){
        head = 0, tail = -1;
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
            if(head <= tail && que[head] < i - k + 1)
                head++;
            while(head <= tail && arr[que[tail]] >= arr[i]){
                tail--;
            }
            que[++tail] = i;
            if(i >= k - 1){
                printf("%d ",arr[que[head]]);
            }
        }
        printf("\n");
        head = 0, tail= -1;
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
            if(head <= tail && que[head] < i - k + 1)
                head++;
            while(head <= tail && arr[que[tail]] <= arr[i]){
                tail--;
            }
            que[++tail] = i;
            if(i >= k - 1){
                printf("%d ",arr[que[head]]);
            }
        }
    }
    return 0;
}