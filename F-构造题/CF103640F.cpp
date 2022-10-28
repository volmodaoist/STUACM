#include <bits/stdc++.h>
#include <limits>
using namespace std;
 
 
typedef long long llong;
typedef unsigned long long ull;
#define  MAXN  500005
 
 
 
/**
 * �������ݱ�֤�����жԵ�֮�䶼����·����������˫��·����
 * Ȼ����̫���ױ������������ "at most one road between each pair of fields"
 * ���·��Ψһ������Ӧ����һ����������Ϊɶ�������� m > n,
 *
 *
 * ��Ҫ�Ѹ���ͼ�ָ���������ͼ��������Ѱ�Ҹ�ߡ����ʲô�ģ�Ȼ���Ҽǲ�ס���ӣ���
 * ��Ȼֻ�������Ӽ�����ô���鼯�����Ѿ������ˣ�
 *  
 * Ŀǰ�ܹ������ó���������Ϣ:
 *  1.  �� i ����أ��������� 2^i������ز����ܴճ������˶���ȵķ�����
 *  2.  д�������Ʊ��ʽ���ɷ��֣�2^i ���� 2^0 + 2^1 ... 2^(i-1) �������ܺ�
 * 
 *  ���ڲ�������ȵ����֮�£�A��Ҫ����B����ôA�õ� ��n�� ���㣬Ȼ��B ���ã��� n-1 ����
 * ��������� B ���ã�Ҳ��ʰȡ֮����ͼ��Ȼ��ͨ��ָ� B������ B ʣ�µ�ȫ��Ҳ�����ܴ��� A 
*/
 
int pt[MAXN];
int find(int x) {
    return x != pt[x] ? pt[x] = find(pt[x]) : x;
}
 
int merge(int x, int y){
    int xr = find(x), yr = find(y);
    if(xr != yr){
        pt[xr] = pt[yr];
        return 1;
    }
    return 0;
}
 
 
int n, m, a, b;
int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
 
    while (cin >> n >> m){
        for (int i = 1; i <= n; i++)
            pt[i] = i;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            if (a == n || b == n)
                continue;
            merge(a, b);
        }
        for (int i = 1; i <= n; i++){
            if(find(i) == find(n - 1)){
                printf("%c", 'B');
            }else{
                printf("%c", 'A');
            }
        }
        cout << endl;
    }
 
    return 0;
}