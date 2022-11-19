#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))

#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
#define  MAXN  505

int a, b, c, n, m;
ill slack[MAXN], ls[MAXN], lt[MAXN];
ill g[MAXN][MAXN], match[MAXN], prec[MAXN], vt[MAXN];

// ����һ������ q��ʹ���뵱ǰ���� u ƥ��, �˴� match ��¼�Ҳඥ��ƥ�����ඥ��
void bfs(int u){
    ill p = 0, q = 0, idx = 0, delta = 0;
    memset(prec, 0, sizeof(prec));
    memset(slack, 0x7f, sizeof(slack));
    match[q] = u;
    do{
        p = match[q], vt[q] = 1, delta = 1e18;
        for (int i = 1; i <= n; i++) {
            if(vt[i]) continue;
            if(slack[i] > ls[p] + lt[i] - g[p][i]){
                slack[i] = ls[p] + lt[i] - g[p][i];
                prec[i] = q;
            }
            // ʹ�ö��������ߵĲ�ֵά���ɳ���slackʹ�価����С��Ȼ������ҳ���С���ɳ��������±�
            if(slack[i] < delta){
                delta = slack[i];
                idx = i;
            }
        }
        // ����ֻ�ں��Ҳඥ�㼯���Ƿ��ڽ�������
        for (int i = 0; i <= n; i++){
            if(vt[i]){
                ls[match[i]] -= delta, lt[i] += delta;
            } else {
                slack[i] -= delta;
            }
        }
        q = idx; // ʹ����С slack �����������Ҳඥ��
    } while (match[q]); // ��ǰ��С slack ����������趥��˵���Ѿ���·������
    while(q) match[q] = match[prec[q]], q = prec[q]; // ���Ž���·���¸���ƥ���ϵ
}


ill KM(){
    memset(match, 0, sizeof(match));
    memset(ls, 0, sizeof(ls));
    memset(lt, 0, sizeof(lt));
    for (int i = 1; i <= n; i++){
        memset(vt, 0, sizeof(vt));
        bfs(i);
    }
    ill ans = 0;
    for (int i = 1; i <= n; i++){
        if(match[i]){
            ans += g[match[i]][i];
        }
    }
    return ans;
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif

    scanf("%d %d", &n, &m);
    memset(g, 0x80, sizeof(g));
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        g[a][b] = max(g[a][b], 0LL + c);
    }
    printf("%lld\n", KM());
    for (int i = 1; i <= n; i++){
        printf("%d ", match[i]);
    }
    printf("\n");
    return 0;
}