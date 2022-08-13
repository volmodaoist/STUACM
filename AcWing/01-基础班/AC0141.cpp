#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

char str[1000010];
int nxt[1000010];

int n;
int kase;
int main(){
    while(scanf("%d", &n) != EOF){
        if(n == 0) break;
        scanf("%s", str + 1);
        for(int i  = 2, j =0; i <= n; i++){
            while(j && str[i] != str[j + 1])
                j = nxt[j];
            if(str[i] == str[j + 1]){
                j++;
            }
            nxt[i] = j; 
        }
        printf("Test case #%d\n", ++kase);
        for(int i = 2; i <= n; i++){
            if(i % (i - nxt[i]) == 0 && nxt[i]){
                printf("%d %d\n", i, i/(i - nxt[i]));
            }
        }
        printf("\n");
    }
    return 0;
}