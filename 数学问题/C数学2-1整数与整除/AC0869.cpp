#include<bits/stdc++.h>
using namespace std;

vector<int> divide(int n){
    vector<int> res;
    int sn = sqrt(n);
    for(int i = 1; i <= sn; i++){
        if(n % i == 0){
            res.push_back(i);
            if(i != n / i) res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int n, x;
int main(){
    scanf("%d", &n);
    for(int i  = 0; i < n; i++){
        scanf("%d", &x);
        auto res = divide(x);
        for(int i = 0; i < res.size(); i++){
            printf("%d ", res[i]);
        }
        printf("\n");
    }
    return 0;
}