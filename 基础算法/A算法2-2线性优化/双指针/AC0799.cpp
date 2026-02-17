#include<bits/stdc++.h>
using namespace std;

int n, ans;
int arr[100005];
int cnt[100005];

int main(){
    scanf("%d",&n);
    for(int i = 0, j = 0; i < n; i++){
        scanf("%d", &arr[i]);
        cnt[arr[i]]++;
        while(cnt[arr[i]] > 1){
            cnt[arr[j++]]--;
        }
        ans = max(ans, i - j + 1);
    }
    printf("%d\n",ans);
    return 0;
}