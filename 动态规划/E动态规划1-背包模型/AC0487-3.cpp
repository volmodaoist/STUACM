#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 32010

int n, m;
int v[MAXN], p[MAXN], q, dp[MAXN];

vector<int> master;         // 存储主件的编号
vector<int> servent[100];   // 储存主件的附件编号

int main(){
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d %d", &v[i], &p[i], &q);
        p[i] = v[i] * p[i]; 
        // 提前计算每个物件的价值，这样下面循环的时候能够少算很多次乘法
        if(q == 0){
            master.push_back(i);
        }else{
            servent[q].push_back(i);
        }
    }
    for(auto i: master){
        for(int j = m; j >= 0; j--){ 
            // 相当于遍历分组背包的每个组
            for(int k = 0; k < (1 << servent[i].size()); k++){ 
                // 获取主件的容积与价值，然后枚举所有附件拿与不拿的组合，这些组合是互斥的，构成一个组
                int vm = v[i], pm = p[i]; 
                for(int s = 0; s < servent[i].size(); s++){
                    if((k >> s) & 1){
                        vm += v[servent[i][s]];
                        pm += p[servent[i][s]]; 
                    }
                }
                if(j >= vm){
                    dp[j] = max(dp[j], dp[j - vm] + pm);
                }
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}