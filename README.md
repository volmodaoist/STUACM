## STUACM

这个项目旨在帮助各位同学们提高算法水平，使用顺序：

1. [信息学奥赛一本通](http://ybt.ssoier.cn:8088/) 

2. [洛谷基础题单](https://www.luogu.com.cn/training/list)

3. [Acwing基础班](https://www.acwing.com/activity/) + [浙大PAT乙级](https://www.patest.cn/practice)

4. [Acwing提高班](https://www.acwing.com/activity/) + [浙大PAT甲级](https://www.patest.cn/practice)

5. [Acwing进阶班](https://www.acwing.com/activity/) + [浙大PAT顶级](https://www.patest.cn/practice)

6. [UVA 练习英文ICPC真题练习](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8) + [LibreOJ训练](https://loj.ac/)

如果是走学术路线，完成环节2~3，保证基本代码编写能力即可，

如果是走工作路线，完成环节1~4，改变方向学习业务技术即可，

改冲[力扣两百题](https://leetcode.cn/problem-list/qg88wci/)、[程序员面试金典](https://leetcode.cn/problem-list/xb9lfcwi/)，以及[剑指Offer](https://leetcode.cn/problem-list/xb9nqhhg/)，然后每周打打[力扣周赛](https://leetcode.cn/contest/)会更合适。

　




## STUACM提问答疑

如有条件可以选择购买《CP4》作为算法训练指导书，

<div align = "center">
<p style="text-align: center">
    <img style="font-size: 13.3328px" 
         src="https://onlinejudge.org/images/banners/1q2pjn4n-front-shortedge-384.jpg" 
         alt="CP4 - Book 1" title="CP4 - Book 1" width="141" height="200">
    <span style="font-size: 13.3328px">&nbsp;</span>
    <img style="font-size: 13.3328px" 
         src="https://onlinejudge.org/images/banners/5j9e26-front-shortedge-384.jpg" 
         alt="CP4 - Book 2" title="CP4 - Book 2" width="141" height="200">
</p>
</div>

[本书](https://cpbook.net/) 难度较大且价格昂贵，其中精选了一些UVA OJ平台的练习，欢迎加入[提问答疑板块](https://github.com/volmodaoist/STUACM/issues) 共同交流这些题目，

此外书中提供了两个可能助于理解本书的参考资料链接：

1. [算法可视化](https://visualgo.net/en)

2. [源代码参考](https://github.com/stevenhalim/cpbook-code)

　



## 刷题模板

```c++
#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10

// 大部分的OJ支持使用bits/std万能头文件
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

typedef long long ill;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
#define  MAXN  100005


int kase;
int main(){
  	// 重定向输入与输出, 便于快速测试
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

  

    return 0;
}
```

　



## 练习题说明

本文给出的练习题都带有标识号，标识号是由平台简称以及题号构成的，

比如 AC0001 是指 AcWing平台之中，题号0001指定的题目，在线测评平台简称详见下表：

|  缩写&简称   |                         在线测评平台                         |
| :----------: | :----------------------------------------------------------: |
|     HDU      | [杭州电子科技大学在线测评平台](https://acm.hdu.edu.cn/listproblem.php?vol=1) |
|  PKU 或 POJ  | [北京大学在线测评平台](http://poj.org/problemlist?volume=1)  |
| AcWing 或 AC |    [AcWing 在线测评平台](https://www.acwing.com/problem/)    |
|   LG 或 P    |      [洛谷题单](https://www.luogu.com.cn/training/list)      |
|  LC 或 LCP   | [力扣题单与力扣杯竞赛真题](https://leetcode.cn/problemset/all/) |
|     LOJ      |                  [LibreOJ](https://loj.ac/)                  |

本项目的笔记建议使用Chrome或Edge浏览器，配合 MathJax 3 Plugin for Github 插件阅读，

否则公式可能无法渲染出来，或者您可以直接把这个项目下载放在本地之后，使用 Typora 打开阅读！





### 竞赛真题VP推荐

- CF-Contest
  - https://codeforces.com/contest/577

- CF-Gym

  - https://codeforces.com/gym/103640

  - https://codeforces.com/gym/103447

  - https://codeforces.com/gym/103443

  - https://codeforces.com/gym/103119

  - https://codeforces.com/gym/103102

  - https://codeforces.com/gym/102984

  - https://codeforces.com/gym/102920
  
  - https://codeforces.com/gym/102822
  
  - https://codeforces.com/gym/102361
