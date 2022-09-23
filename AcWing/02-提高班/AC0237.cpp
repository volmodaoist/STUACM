#include<bits/stdc++.h>
using namespace std;


#define MAXN 300005

int id;
map<int, int >hash_in;
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


int n, m, a, b, e,kase;
int main(){
    scanf("%d", &kase);
    while(kase--){
        scanf("%d", &n);
        
        hash_in.clear();
        id = 0, m = 2 * n + 10; 
        
        for(int i = 0; i <= m; i++)
            pt[i] = i;
        vector<pair<int,int>> judge; 
        for(int i = 0; i < n; i++){
            scanf("%d %d %d", &a, &b, &e);
            a = get(a), b = get(b);
            if(e){
                if(find(a) != find(b)){
                    pt[find(a)] = pt[find(b)];
                }
            }else{
                judge.emplace_back(a, b);
            }
        }
        bool fg = true;
        for(int i = 0; i < judge.size(); i++){
            if(find(judge[i].first) == find(judge[i].second)){
                fg = false;
                break;
            }
        }
        cout << (fg ? "YES" : "NO") << endl;
    }
    return 0;
}