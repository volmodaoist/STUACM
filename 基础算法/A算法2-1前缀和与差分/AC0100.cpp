#include<bits/stdc++.h>
using namespace std;

typedef long long Long;
int n;
int arr[100005];
int dif[100005];

int main(){
    while(scanf("%d", &n) != EOF){
        Long pos = 0, neg = 0;
        for(int i = 1 ; i <= n; i++){
            scanf("%d", &arr[i]);
            dif[i] = arr[i] - arr[i - 1];
        }
        for(int i = 2; i <= n; i++){
            if(dif[i] > 0){
                pos += dif[i];
            }else{
                neg -= dif[i];
            }
        }
        printf("%lld\n", min(pos, neg)  + abs(pos - neg));
        printf("%lld\n", abs(pos - neg) + 1);
    }
    return 0;
}