#include<bits/stdc++.h>
using namespace std;

#define MAXN  40005
#define BASE  20000

int n, m, id;
map<int, int> hash_in;

int get(int x){
    if(!hash_in.count(x)){
        hash_in[x] = ++id;
    }
    return hash_in[x];
}

int pt[MAXN];
int find(int x){
    return pt[x] != x ? pt[x] = find(pt[x]) : x;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= 2 * BASE; i++)
        pt[i] = i;
    int ans = m;
    for(int i = 0; i < m; i++){
        char str[5];
        int a, b, t, ar, br;
        scanf("%d %d %s",  &a, &b, str);
        a = get(a - 1), b = get(b), t = (str[0] == 'o' ? 1 : 0);
        if(t){
            if(find(a) == find(b)){
                ans = i;
                break;
            }
            pt[find(a + BASE)] = pt[find(b)];
            pt[find(a)] = pt[find(b + BASE)];
        }else{
            if(find(a + BASE) == find(b)){
                ans = i;
                break;
            }
            pt[find(a)] = pt[find(b)];
            pt[find(a + BASE)] = pt[find(b + BASE)];
        }
    }
    printf("%d\n", ans);
    return 0;
}