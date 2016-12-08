# 尺取法 

尺取法通常是指对数组保存一对下标（起点、终点），然后根据实际情况交替推进两个端点直到得出答案的方法，
这种操作很像是尺蠖爬行的方式。尺蠖在日文称为尺取虫，这里直接使用了日文原文的汉字来命名。

## 描述

>### POJ 3061 Subsequence
>给定长度为`n`的一个正整数序列`a[0],a[1],...,a[n-1]`以及一个整数`S`，求出总和不小于`S`的连续子序列的最小值。如果不存在，则输出0。
设以`a[left]`开始总和最初大于等于`S`的连续子序列为`a[left],a[left+1],...,a[right-1]`，记为`[left, right)`，即`sum{ [left, right) } >= S`。
因为所有元素都大于等于0，所以序列`sum{ [left+1, right-1) } < sum{ [left, right-1) } < S`，
所以从`a[left+1]`开始总和最初大于等于`S`的连续子序列如果是`left+1, right')`，则必有`right'>=right`，
即当左端点右移时，右端点要么不动，要么右移，由此性质便可得到尺取算法。

```C++
int left = right = 0, ans = INF, sum = 0;
while (true)
{
    while (right < n && sum < s) sum += a[right++];
	if (sum < s) break;
	ans = min(ans, right - left);
	sum -= a[left++];
}
```

## 归纳

尺取的题目大体可分为两类，一类是在满足条件的情况下使序列尽可能长，另一类是使序列长度尽可能短

### 第一类题目

上题为第一类题目，核心可概括为一下三点  
**前提：** 连续子序列  
**条件：** 元素和sum>=S  
**目标：** 长度尽可能长ans=max{right-left}  

代码框架可概括为三部分
```C++
初始化left = right = 0，ans = 0，sum = 0此时不满足题目条件
while (true)
{
    1.推进右端点直至满足条件或到序列末端
    (若仍不能满足条件，退出循环)

    2.更新答案
    3.左端点推进一步
}
```

### 第二类题目

POJ 3320 Jessica's Reading Problem  
**前提：** 连续子序列  
**条件：** 子序列中不同元素数目=整个序列中不同元素数目  
**目标：** 长度尽可能短ans=min{right-left}  

```C++
初始化left = right = 0, ans = INF, cnt = 0
```