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
#define  MAXN  1000005
 
vector<int> edges[MAXN];
vector<int> ans;
int w[MAXN];
int n, x, t, root, total = 0;
 
int dfs(int u, int father, int target){
    int sumv = w[u];
    for (int v : edges[u]) {
        if(v == father)
            continue;
        sumv += dfs(v, u, target);
        // �տ�ʼ�ж��߼�д���˴˴���������������Ҷ�ӽڵ��ǲ������ж��ģ�
    }

    // �ؼ����ж��߼���ǧ���д��for���棬����Ҷ�ӽڵ��޷����ж�
    if(sumv == target){
        if (u != root){
            ans.push_back(u);
        }
        sumv = 0;
    }
    return sumv;
}
 
/**
 * ������һ���򻯰汾��ԭ������CF DIV2-398Round, 
 * https://codeforces.com/contest/767/problem/C
 
 * �򻯰�Ԫ��ֻ�� ���������������۵�315������:
 * https://leetcode.cn/problems/create-components-with-same-value/
 */ 

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
 
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d %d", &x, &t);
        edges[i].emplace_back(x);
        edges[x].emplace_back(i);
        w[i] = t;
        total += t;
        if(x == 0) root = i;
    }
 
 
    if (total % 3 == 0){
        dfs(root, 0, total / 3);
    }
 
 
    // ���ڴ��ڸ���������ǰ׺�͵Ľ���п��ܻ���ֲ�ֹ������������target 
    if (ans.size() >= 2) {
        for (int i = 0; i < 2; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    } else {
        printf("-1");
    }
    return 0;
}