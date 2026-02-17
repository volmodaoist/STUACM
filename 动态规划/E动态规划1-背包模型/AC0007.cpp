#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
int n, m;
int v[MAXN], w[MAXN], s[MAXN];
typedef struct _Staff{
    int v, w;
}Staff;

int dp[MAXN];
vector<Staff> staffs;


int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &v[i], &w[i], &s[i]);
        if(s[i] == -1){
            s[i] = 1;
        }else if(s[i] == 0){
            s[i] = m / v[i];
        }
    }
    
    int nums, base;
    for(int i = 0; i < n; i++){
        nums = s[i], base = 1;
        while(nums >= base){
            staffs.push_back({base * v[i], base * w[i]});
            nums -= base;
            base <<= 1;
        }
        if(nums) staffs.push_back({nums * v[i], nums * w[i]});
    }
    
    for(int i = 0; i < staffs.size(); i++){
        for(int j = m; j >= staffs[i].v; j--){
            dp[j] = max(dp[j], dp[j - staffs[i].v] + staffs[i].w);
        }
    }
    
    cout << dp[m] << endl;
    return 0;
}