#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  MAXN  800005

int flaw[MAXN], n;

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &flaw[i]);
        flaw[n + i] = flaw[i];
    }

    int i = 1, j = 2, k = 0;
    while (i <= n && j <= n) {
        for (k = 0; k < n && flaw[i + k] == flaw[j + k]; k++);
        if (flaw[i + k] > flaw[j + k]) {
            i = i + k + 1;
        } else {
            j = j + k + 1;
        }
        if(i == j) j++;
    }
    int idx = min(i, j);
    for (int i = idx, len = 1; len <= n; i++, len++){
        printf("%d ", flaw[i]);
    }
    printf("\n");
    return 0;
}