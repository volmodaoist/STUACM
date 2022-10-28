#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
#define  MAXN  100005

char a[MAXN], b[MAXN];
int kase, n, ans1, ans2, lo, hi;

/**
 * 本题来自于 ICPC2021 中国台北区域赛，
 * 意思是说给定两个长度相等的字符串s1与s2 (n <= 1000))，对应位相等于则称一个匹配，
 * 我们可以翻转s2某个子串 s2[lo,hi] 使得匹配数增加，要求最大的匹配数，如果存在多个答案就输出翻转长度最小的一个， 
 */ 


// 本题链接  https://codeforces.com/gym/103443/problem/B
// 本题题面  https://drive.google.com/file/d/1YUMxajkblszqjcVhb3ksvv1UL44JOlJT/view
int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d", &kase);
    while(kase--){
        scanf("%d", &n);
        scanf("%s", a + 1);
        scanf("%s", b + 1);
        ans1 = ans2 = 0, lo = hi = 1;
        for (int i = 1; i <= n; i++) {
            if(a[i] == b[i]){
                ans1++, ans2++;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                int tmp = 0;
                
                // [1,i) 不变 
                for (int k = 1; k < i; k++){
                    if (b[k] == a[k]){
                        tmp++;
                    }
                }

                // 翻转 [i, j]
                for (int k = j, h = i; k >= i; h++, k--) {
                    if(b[k] == a[h]){
                        tmp++;
                    }
                }

                // [j+1,n) 不变 
                for (int k = j + 1; k <= n; k++){
                    if(b[k] == a[k]){
                        tmp++;
                    }
                }

                if (tmp > ans2 || (tmp == ans2 && j - i < hi - lo)) {
                    ans2 = tmp;
                    lo = i;
                    hi = j;
                }
            }
        }
        // 直接翻转肯定不行，只要利用指针正序与逆序比较即可，复杂度 O(n^3) 但是能过，
        // 最终打印匹配数、翻转之后能够取得的最大匹配数、翻转区间的左端点、翻转区间的右端点
        printf("%d %d %d %d\n", ans1, ans2, lo, hi);
    }
    return 0;
}