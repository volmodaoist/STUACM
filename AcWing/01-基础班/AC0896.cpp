#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

int n;
int main(){
    scanf("%d", &n);
    vector<int> s(n), g;
    for(int i = 0; i < n; i++){
        scanf("%d", &s[i]);
    }
    g.push_back(s[0]);
    for(int i = 1; i < n; i++){
        if(s[i] > g.back()){
            g.push_back(s[i]);
        }else{
            *lower_bound(g.begin(), g.end(), s[i]) = s[i];
        }
    }
    printf("%d\n", g.size());
    return 0;
}