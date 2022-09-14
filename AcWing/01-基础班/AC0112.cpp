#include<bits/stdc++.h>
using namespace std;

#define MAXN    3000
#define eps     1e-5
#define lt      second
#define rt      first 

// rgs means ranges

int n, d, a, b, x, y;
pair<double,double> rgs[MAXN];

int main(){
    bool success = true;
    scanf("%d %d", &n, &d);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &x, &y);
        if(y > d){
            success = false;
        }
        double len = sqrt(pow(d, 2) - pow(y, 2)); 
        rgs[i] = {x + len, x - len};
    }
    if(!success){
        printf("-1\n");
    }else{
        sort(rgs, rgs + n);
        int ans = 0;
        double ed = -2e9;
        for(int i = 0; i < n; i++){
            if(ed < rgs[i].lt){
                ans++;
                ed = rgs[i].rt;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}