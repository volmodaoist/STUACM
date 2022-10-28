#include<bits/stdc++.h>
#include<limits.h>
using namespace std;


typedef pair<int ,int > ii;
vector<ii> ab;

vector<int> mul(vector<int> &a, int b){
    vector<int> ans;
    int t = 0;
    for(int i = 0; i < a.size(); i++){
        t += a[i] * b;
        ans.push_back(t % 10);
        t /= 10;
    }
    while(t){
        ans.push_back(t % 10);
        t /= 10;
    }
    return ans;
}

// 传入的大整数是逆序存储的
vector<int> div(vector<int> &a, int b){
    vector<int> ans;
    bool is_first = true;
    for(int i = a.size() - 1, t = 0; i >= 0; i--){
        t = t * 10 + a[i];
        int x = t / b;

        // 如果首位等于0则不应放入答案之中
        if(!is_first || x){
            is_first = false;
            ans.push_back(x);
        }
        t %= b;
    }
    reverse(ans.begin(), ans.end());
    return ans;
} 

vector<int> max_vec(vector<int> a, vector<int> b){
    if(a.size() > b.size()) return a; 
    if(b.size() > a.size()) return b;
    return (vector<int>(a.rbegin(), a.rend()) > vector<int>(b.rbegin(), b.rend())) ? a : b;
}

int a, b, n;
int main(){
    scanf("%d", &n);
    for(int i = 0; i <= n; i++){
        scanf("%d %d", &a, &b);
        ab.emplace_back(a,  b);
    }
    
    // 国王总是站在最前面，所以排序的时候不排国王
    sort(ab.begin() + 1, ab.end(), [](const ii &x, const ii &y){
        return x.first * x.second < y.first * y.second; 
    });
    
    
    vector<int> base(1, 1), ans(1, 0);
    for(int i = 0; i < ab.size(); i++){
        if(i){
            ans = max_vec(ans, div(base, ab[i].second));
        }
        base = mul(base, ab[i].first);
    }
    
    for(int i = ans.size() - 1; i >= 0; i--){
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}