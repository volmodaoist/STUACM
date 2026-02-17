#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 1000005
int a[MAXN];
int b[MAXN];
int n;
int m;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    int j = 0;
    for(int i = 0; i < m; i++){
        if(j < n && a[j] == b[i]) 
            j++;
    }
    cout << (j == n ? "Yes" : "No") << endl;
    return 0;
}