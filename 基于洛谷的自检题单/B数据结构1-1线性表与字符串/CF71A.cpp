#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


// https://codeforces.com/problemset/problem/71/A
int main(){ 
    int n;
    char str[150];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", str);
        int len = strlen(str);
        if(len <= 10){
            printf("%s\n", str);
        }else{
            printf("%c%d%c\n", str[0], len - 2, str[len - 1]);
        }
    }
    return 0;
}