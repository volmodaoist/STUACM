#include <bits/stdc++.h>
#include <limits.h>

using namespace std;

#define MAXN 100005

int n, m;
typedef unsigned long long ULL;

ULL P = 131;
ULL p[MAXN], h[MAXN];


ULL query(int l, int r){
    return h[r] - h[l - 1] * p[r - l + 1];
}

string str;

int main(){
    cin >> n >> m;
    cin >> str;
    
    h[0] = 0, p[0] = 1;
    for(int i = 1; i <= n; i++){
        p[i] =  p[i - 1] * P;
        h[i] =  h[i - 1] * P  + str[i - 1];
    }
    int l1,r1, l2, r2;
    while(m--){
        cin >> l1 >> r1 >> l2 >> r2;
        if(query(l1, r1) == query(l2, r2)){
            puts("Yes");
        }else{
            puts("No");
        }
    }
    return 0;
}