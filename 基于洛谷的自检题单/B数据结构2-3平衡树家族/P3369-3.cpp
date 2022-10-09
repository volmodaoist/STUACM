#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long llong;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
#define  MAXN  100005



int idx = 1;
int tr[MAXN << 5][2], siz[MAXN << 5];

// 使用零代表空指针，虚设一个超级节点 idx = 1
int new_node(){
    siz[++idx] = tr[idx][0] = tr[idx][1] = 0;
    return idx;
}

// 插入元素 x，插入数量 c
void ins(int x, int c){
    int u = 1;
    for (int i = 30; i >= 0; i--){
        int v = (x >> i) & 1;
        if(!tr[u][v]){
            tr[u][v] = new_node();
        }
        u = tr[u][v];
        siz[u] += c;
    }
}

int get_kth(int k){
    int u = 1, ans = 0;
    for (int i = 30; i >= 0; i--){
        if (siz[tr[u][0]] >= k){
            u = tr[u][0];
        }else{
            ans |= (1 << i);
            k -= siz[tr[u][0]];
            u = tr[u][1];
        }
    }
    return ans;
}

int get_rank(int v){
    int u = 1, ans = 0;
    for (int i = 30; i >= 0; i--){
        if ((v >> i) & 1){
            ans += siz[tr[u][0]];
            u = tr[u][1];
        }else{
            u = tr[u][0];
        }
    }
    return ans;
}

/**
 *   注意 01-Trie 平衡树的 rank 是从零开始计算的，但是 kth 从一开始计算，本题给出 1-base 序列，
 * 因此rank 返回之前需要 + 1，同时由于 01-Trie 返回节点所在的索引是不太方便的，其获取前驱与后继
 * 主要依赖 rank、kth 两个操作，前驱也即寻找 v 前一个排名，后继也即寻找 v + 1 第一个排名，记得+1
 */ 

int get_prev(int v){
    return get_kth(get_rank(v));
}

int get_succ(int v){
    return get_kth(get_rank(v + 1) + 1);
}

int kase;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    int n, offset = 1e7;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int op, x;
        scanf("%d %d", &op, &x);
        if (op == 1) ins(x + offset,  1);
        if (op == 2) ins(x + offset, -1);
        if (op == 3) printf("%d\n", get_rank(x + offset) + 1);
        if (op == 4) printf("%d\n", get_kth(x) - offset);
        if (op == 5) printf("%d\n", get_prev(x + offset) - offset);
        if (op == 6) printf("%d\n", get_succ(x + offset) - offset);
    }

    return 0;
}