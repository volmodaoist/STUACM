#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000005

int n, kase, a, b;
int pt[MAXN], d[MAXN], siz[MAXN];
int find(int x){
    if(x != pt[x]){
        int rt = find(pt[x]);
        d[x] += d[pt[x]];
        pt[x] = rt;
    }
    return pt[x];
}


/**
 * 本题 merge 这个地方有一个细节，xr 一列接在 yr 一列身后的时候,
 * 此时 xr 一列所有节点都需要加上 yr 一列的战舰数(使用 siz 数组维护)，但在更新 d[xr] 变量的时候，
 * 使用的表达式
 *          并非 d[xr] += siz[yr],
 *          而是 d[xr]  = siz[yr]，
 * 其实使用 += 也是能够通过的，因为路径压缩之后距离会以权值的方式存入 d 数组，
 * 再次强调， d[x] 代表 x 到达(路径压缩之前的)父节点的距离!!! 类似于 AC0240. 食物链!
*/ 
int merge(int x, int y){
    int xr = find(x), yr = find(y);
    if(xr != yr){
        pt[xr] = yr;
        d[xr] += siz[yr];
        siz[yr] += siz[xr]; 
        return 1;
    }
    return 0;
}

// 本题一个坑在于出现的编号有可能大于n
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= 30010; i++)
        pt[i] = i, d[i] = 0, siz[i] = 1;
    for(int i = 0; i < n; i++){
        char op[3];
        scanf("%s %d %d", op, &a, &b);
        if(op[0] == 'M'){
            merge(a, b);
        }else{
            if(find(a) == find(b)){
                printf("%d\n", max(0, abs(d[a] - d[b]) - 1));
            }else{
                printf("-1\n");
            }
        }
    }
    return 0;
}