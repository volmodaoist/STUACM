#include<bits/stdc++.h>
using namespace std;

bool is_prime(int n){
    if(n < 2)
        return false;
    int sn = sqrt(n);
    for(int i = 2; i <= sn; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int n, x;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        printf("%s\n", is_prime(x) ? "Yes" : "No");
    }
    return 0;
}