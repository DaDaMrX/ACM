# ST

## 算法描述

* 如何快速查询区间最值？
  * 空间换时间，$O(nlogn)$预处理，$O(1)$查询。
* ST原理
  * 用$dp[i][j]$表示起点为$i$，长度为$2^n$的区间，也就是区间$[i, 1 + 2^j - 1]$内的最大值。
  * 那么任意区间$[a,b]$内的最大值就是$max\{ dp[a][k], dp[b-2^k+1][k]\} $。
  * 其中$k$是满足$2^k\le b-a+1$(区间长度)的最大的$k$，即$k=\lfloor log_2(b-a+1)\rfloor $。
* 如何得到dp数组？
  * 动态规划。
  * 显然$dp[i][0] = a[i] (1 \le i \le n)$，那么，在已知$dp[i][j - 1] (1 \le i \le n)$的情况下如何得到$dp[i][j - 1] (1 \le i \le n)$？
  * $dp[i][j]=max \{ dp[i][j - 1], dp[i+2^{j - 1}, j - 1] \} $，即把区间$[i,i+2^j-1]$分成了$[i,i+2^{j-1}-1]$和$[i+2^{j-1},i+2^j-1]$两个部分，这两个部分已经求出了。 
* 其中要频繁用到求以$2$为底的对数的下取整的操作，可以预处理得到。

## 代码实现

```c++
int a[N];
int dp[N][20], lg[N];
void ST(int n)
{
	lg[0] = -1;
	for (int i = 1; i <= n; i++)
	{
		lg[i] = (i & (i - 1)) == 0 ? lg[i - 1] + 1 : lg[i - 1];
		dp[i][0] = a[i];
	}
	for (int j = 1; j <= lg[n]; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
}
int rmq(int left, int right)
{
	int k = lg[right - left + 1];
	return max(dp[left][k], dp[right - (1 << k) + 1][k]);
}
```

