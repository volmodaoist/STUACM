## STUACM

这个项目旨在帮助各位同学们提高算法水平，使用顺序：

1. [信息学奥赛一本通](http://ybt.ssoier.cn:8088/) 

2. [洛谷基础题单](https://www.luogu.com.cn/training/list)

3. [Acwing基础班](https://www.acwing.com/activity/) + [浙大PAT乙级](https://www.patest.cn/practice)

4. [Acwing提高班](https://www.acwing.com/activity/) + [浙大PAT甲级](https://www.patest.cn/practice)

5. [Acwing进阶班](https://www.acwing.com/activity/) + [浙大PAT顶级](https://www.patest.cn/practice)

6. [UVA 练习英文ICPC真题练习](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8)

如果是走工作路线，完成环节2~4即可改变方向，

改冲[力扣两百题](https://leetcode.cn/problem-list/qg88wci/)、[程序员面试金典](https://leetcode.cn/problem-list/xb9lfcwi/)，以及[剑指Offer](https://leetcode.cn/problem-list/xb9nqhhg/)，然后每周打打力扣周赛会更合适。

　




## STUACM提问答疑

如有条件可以选择购买《CP4》作为算法训练指导书，

[本书](https://cpbook.net/) 难度较大且价格昂贵，其中精选了一些UVA OJ平台的练习，欢迎加入[提问答疑板块](https://github.com/volmodaoist/STUACM/issues) 共同交流这些题目，

此外书中提供了两个可能助于理解本书的参考资料链接：

1. [算法可视化](https://visualgo.net/en)

2. [源代码参考](https://github.com/stevenhalim/cpbook-code)

　



## 刷题模板

```c++
#define _OJ_ONLINE_JUDGE_
#define min3(x,y,z)    (min(min(x,y),z))
#define min4(x,y,u,v)  (min(min(x,y),min(u,v)))
#define max3(x,y,z)    (max(max(x,y),z))
#define max4(x,y,u,v)  (max(max(x,y),max(u,v)))

#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
//大部分的OJ支持使用bits/std万能头文件，

typedef long long LL;
typedef pair<int,int> Point;


int main(){
    //重定向输入与输出, 便于快速测试
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("./test.in","r",stdin);
    freopen("./test.out","w",stdout);
    #endif
    #ifndef  _OJ_ONLINE_JUDGE_
    std::ios::sync_with_stdio(false);
	#endif

    
    return 0;
}
```
