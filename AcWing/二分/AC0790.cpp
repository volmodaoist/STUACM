#include<bits/stdc++.h>
using namespace std;

double n;
double binary_search(){
    double lo = -10000, md, hi = 10000;
    while(hi - lo >= 1e-7){
        md = (lo + hi) / 2;
        if((md * md * md) >= n){
            hi = md;
        }else{
            lo = md;
        }
    }
    return lo;
}


int main(){
    // 左右边界要按题目给定的边界来设, 而非 0 ~ n, 
    // 因为形如1/8开三次方根等于1/2大于给定 n = 1/8
    while(scanf("%lf", &n) != EOF){
        printf("%.6lf", binary_search());
    }
    return 0;
}