#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	CLEAR(A,x)  (memset(A,x,sizeof(A)))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <limits>
using namespace std;


typedef long long Long;
typedef unsigned long long ULL;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  fi    first
#define  se    second
#define  MAXN  100005

typedef long long LLong; 

int n, m, arr[100005];
LLong tr[400020], tag[400200];

inline void buildtree(int k, int lo, int hi){
    tag[k] = 0;
    if(lo == hi){
        tr[k] = arr[lo];
        return;
    }
    int md = lo + (hi - lo) / 2;
    buildtree(2 * k, lo, md);
    buildtree(2 * k + 1, md + 1, hi);
    tr[k] = tr[2 * k] + tr[2 * k + 1];
}


inline void add(int k, int lo, int hi, LLong i, LLong j, LLong c){
    if(lo == i && hi == j){
        tag[k] += c;
        return;
    }
    tr[k] += (j - i + 1) * c; // 区间里面每个元素都增加c，总结增加 (j-i+1)*c
    int md = lo + (hi - lo) / 2;
    if(j <= md){
        add(2 * k, lo, md, i, j, c);
    }else if(i > md){
        add(2 * k + 1, md + 1, hi, i, j, c);
    }else{
        add(2 * k, lo, md, i, md, c);
        add(2 * k + 1, md + 1, hi, md + 1, j, c);
    }
}


// p 代表线段树查询路径上面的懒标记总和
LLong calc(int k, int lo, int hi, int i, int j, LLong p){
    p += tag[k];
    if(lo == i && hi == j){
        return p * (j - i + 1) + tr[k];
    }
    int md = lo + (hi - lo) / 2;
    if(j <= md){
        return calc(2 * k, lo, md, i, j, p);
    }else if(i > md){
        return calc(2 * k + 1, md + 1, hi, i, j, p);
    }else{
        return calc(2 * k, lo, md, i, md, p) + calc(2 * k + 1, md + 1, hi, md + 1, j, p);
    }
    return 0;
}

int kase;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    while (scanf("%d %d", &n, &m) != EOF){
        for (int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
        }
        buildtree(1, 1, n);

        int op, a, b, c;
        for (int i = 1; i <= m; i++){
            scanf("%d", &op);
            if(op == 1){
                scanf("%d %d %d", &a, &b, &c);
                add(1, 1, n, a, b, c);                
            }else if(op == 2){
                scanf("%d %d", &a, &b);
                printf("%lld\n", calc(1, 1, n, a, b, 0L));
                
            }
        }
    }
    return 0;
}


// #include  "bits/stdc++.h"
// using namespace std;

// typedef long long LL;
// typedef unsigned long long ULL;
// #define MAXN 1000010
// #define __int64 LL

// ULL arr[MAXN], tree[MAXN << 2], lazy[MAXN << 2];

// inline __int64 ls(__int64 p) { return p << 1; }
// inline __int64 rs(__int64 p) { return p << 1 | 1; }

// inline void merge(__int64 node){
// 	tree[node] = tree[ls(node)] + tree[rs(node)];
// }

// inline void mark(__int64 node, __int64 lo, __int64 hi,__int64 k) {
// 	lazy[node] += k;
// 	tree[node] += k * (hi - lo + 1);
// }

// inline void dismantle(__int64 node, __int64 lo, __int64 hi) {
// 	__int64 mi = lo + (hi - lo) / 2;
// 	mark(ls(node), lo, mi, lazy[node]);
// 	mark(rs(node), mi+1, hi, lazy[node]);
// 	lazy[node] = 0;
// }


// void buildTree(__int64 node, __int64 lo, __int64 hi) {
// 	lazy[node] = 0;
// 	if (lo == hi) {
// 		tree[node] = arr[lo];
// 	} else {
// 		__int64 mi = lo + (hi - lo) / 2;
// 		buildTree(ls(node), lo, mi);
// 		buildTree(rs(node), mi + 1, hi);
// 		merge(node);
// 	}
// }

// /// <summary>
// ///	 [L,R] 是将要修改的的区间
// /// </summary>
// void update(__int64 L, __int64 R, __int64 lo, __int64 hi, __int64 node, __int64 k) {
// 	if (L <= lo && hi <= R) {
// 		tree[node] += k * (hi - lo + 1);
// 		lazy[node] += k;
// 	} else {
// 		dismantle(node, lo, hi);
// 		__int64 mi = lo + (hi - lo) / 2;
// 		if (L <= mi) update(L, R, lo, mi, ls(node), k);
// 		if (R > mi) update(L, R, mi + 1, hi, rs(node), k);
// 		merge(node);
// 	}
// }


// __int64 query(__int64 qx, __int64 qy, __int64 lo, __int64 hi, __int64 node) {
// 	__int64 ans = 0;
// 	if (qx <= lo && hi <= qy) {
// 		return tree[node];
// 	}
// 	__int64 mi = lo + (hi - lo) / 2;
// 	dismantle(node, lo, hi);
// 	if (qx <= mi) ans += query(qx, qy, lo, mi, ls(node));
// 	if (qy > mi) ans += query(qx, qy, mi + 1, hi, rs(node));
// 	return ans;
// }





// int main() {
// 	#ifdef ONLINE_JUDEG
// 	freopen("test.in", "r", stdin);
// 	freopen("test.out", "w", stdout);
// 	#endif
// 	std::ios::sync_with_stdio(false);
// 	int n, m, t, x, y, k;
// 	cin >> n >> m;
// 	for (int i = 1;i <= n;i++) {
// 		cin >> arr[i];
// 	}
// 	buildTree(1, 1, n);
// 	while (m--) {
// 		cin >> t;
// 		switch (t) {
// 		case 1:
// 			cin >> x >> y >> k;
// 			update(x, y, 1, n, 1, k);
// 			break;
// 		case 2:
// 			cin >> x >> y;
// 			cout << query(x, y, 1, n, 1) << endl;
// 			break;
// 		}
// 	}
// 	return 0;
// }