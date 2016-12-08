# Round 4

>12.6-12.13  
Week 15

## 1. A. Innovative Experiment (数论)

* ### Description
    给出一个整数k（1<=k<=1e18），要求找到一个长度为n（1<=n<=1e5）的轮换，
恰好复合k次之后成为恒等变换。若有多个满足要求的解，输出任意一个即可。

* ### Analysis
    若k也小于等于1e5，则可以找这样一个长度也为k的轮换，每次都把第一个元素放到最后，这样k次之后恰好回到原始状态。

    关键就在于当复合次数k大于1e5时，如何找到慢足条件的长度小于等于1e5的序列。

## 2. B. Epic Battle (水)

* ### Description

* ### Analysis

## 3. C. Pink Elephants (组合数)

* ### Description
    求组合数C(n, m)，（1<=n,m<=200），结果对1e9+7取模。

* ### Solution
    板题，取模，数据范围是关键。

## 4. D. Broadcasting (水)

* ### Description

* ### Analysis
    数学上ans=ceil(log(n)/log(k+1))，但计算对数特别容易丢失精度，改用while累乘。

## 7. G. Procrastination (贪心)

* ### Description

* ### Solution

## 8. H. The Longest Good Substring (尺取)

* ### Description

* ### Solution

## 10. J. Secret Laboratory 

## 11. K. Triskaidekaphobia 

* ### Description
    给出一个长度位n（1<=n<=1e3）的只包含1和3的字符串，问最少删除多少字符后可以试剩余的字符串中不包含"13"子串。

* ### Solution

## 12. L. Make Your Donation Now 

* ### Description
    有n个人向一个网站捐钱，每个人有一个最小捐赠金额a[i]和最大捐赠金额b[i]，同时网站会设置一个最小
    捐赠金额p，对于每个人，如果a[i]>p，他会捐赠a[i]，如果b[i]<p，他就不会捐赠，如果a[i]<p<b[i]，
    则他会捐赠p。问网站管理员要获得最大的捐赠总金额，应该如何设置每个人的最小捐赠金额p。如果有多个
    p可以满足最大捐赠总数，输出最小结果。

* ### Solution
