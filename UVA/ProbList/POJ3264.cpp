#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;


typedef long long Long;
typedef unsigned long long ULL;

#define MAXN  50005
int n, q;
int arr[MAXN];
int maxv[MAXN][20], minv[MAXN][20];

int main(){
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        minv[i][0] = maxv[i][0] = arr[i];
    }
    for (int j = 1; j <= 20; j++){
        for (int i = 1; i + (1 << j) - 1 <= n; i++){
            maxv[i][j] = max(maxv[i][j - 1], maxv[i + (1 << (j - 1))][j - 1]);
            minv[i][j] = min(minv[i][j - 1], minv[i + (1 << (j - 1))][j - 1]);
        }
    }
    int a, b, z, s;
    while(q--){
        scanf("%d %d", &a, &b);
        // printf("b = %d\n", b);
        // printf("a = %d\n", a);
        // printf("z = %d\n", (int)log2(b - a + 1));
        z = (int)log2(b - a + 1);
        s = max(maxv[a][z], maxv[b - (1 << z) + 1][z]) - min(minv[a][z], minv[b - (1 << z) + 1][z]);
        printf("%d\n", s);
    }
    
    return 0;
}