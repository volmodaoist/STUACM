#include<bits/stdc++.h>
using namespace std;

#define MAXN  20000

int n, m, id;
map<int, int> hash_in;

int get(int x){
    if(!hash_in.count(x)){
        hash_in[x] = ++id;
    }
    return hash_in[x];
}

int pt[MAXN], d[MAXN];
int find(int x){
    if(x != pt[x]){
        int rt = find(pt[x]);
        d[x] ^= d[pt[x]];
        pt[x] = rt;
    }
    return pt[x];
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= 2 * m; i++)
        pt[i] = i;
    int ans = m;
    for(int i = 0; i < m; i++){
        char str[5];
        int a, b, t, ar, br;
        scanf("%d %d %s",  &a, &b, str);
        a = get(a - 1), b = get(b), t = (str[0] == 'o' ? 1 : 0);
        ar = find(a), br = find(b);
        if(ar != br){
            pt[ar] = pt[br];
            d[ar] = d[a] ^ d[b] ^ t;
        }else{
            if((d[a] ^ d[b]) != t){
                ans = i;
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}