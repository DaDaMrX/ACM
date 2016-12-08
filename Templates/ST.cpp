/************************************************************
ST表
O(nlogn)预处理，静态查询区间最小值（下标）/最大值（下标）/最大最小值之差

1. 数组a[]，输入的数据，下标从1到n
************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int a[N];
int dp[N][20], lg[N];
void ST(int n)
{
	lg[0] = -1;
	for (int i = 1; i <= n; i++)
	{
		lg[i] = ((i & (i - 1))) == 0 ? lg[i - 1] + 1 : lg[i - 1];
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

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	ST(n);
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", rmq(a, b));
	}
	return 0;
}

/********************
Input
5
2 3 0 1 4
5
1 5
2 4
1 3
1 1
4 4

Output
4
3
3
2
1

********************/

//RMQ最大值（最小值）下标
//初始化和查询时，加等号返回第一个最大（小）值的下标，不加等号返回最后一个
int a[N];
int dp[N][20], lg[N];
void ST(int n)
{
	lg[0] = -1;
	for (int i = 1; i <= n; i++)
	{
		lg[i] = ((i & (i - 1))) == 0 ? lg[i - 1] + 1 : lg[i - 1];
		dp[i][0] = i;
	}
	for (int j = 1; j <= lg[n]; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
		{
			int x = dp[i][j - 1], y = dp[i + (1 << (j - 1))][j - 1];
			dp[i][j] = a[x] >= a[y] ? x : y;
		}
}
int rmq(int left, int right)
{
	int k = lg[right - left + 1];
	int x = dp[left][k], y = dp[right - (1 << k) + 1][k];
	return a[x] >= a[y] ? x : y;
}

//RMQ最大值最小值之差
int a[N];
int dpmax[N][20], dpmin[N][20], lg[N];
void ST(int n)
{
	lg[0] = -1;
	for (int i = 1; i <= n; i++)
	{
		lg[i] = ((i & (i - 1))) == 0 ? lg[i - 1] + 1 : lg[i - 1];
		dpmax[i][0] = dpmin[i][0] = a[i];
	}
	for (int j = 1; j <= lg[n]; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
		{
			dpmax[i][j] = max(dpmax[i][j - 1], dpmax[i + (1 << (j - 1))][j - 1]);
			dpmin[i][j] = min(dpmin[i][j - 1], dpmin[i + (1 << (j - 1))][j - 1]);
		}
}
int rmq(int left, int right)
{
	int k = lg[right - left + 1];
	int maxx = max(dpmax[left][k], dpmax[right - (1 << k) + 1][k]);
	int minx = min(dpmin[left][k], dpmin[right - (1 << k) + 1][k]);
	return maxx - minx;
}

//RMQ最大值（最小值）下标从0开始 ？


//Usage
int main()
{
	int n;
	scanf("%d%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	ST(n);
	scanf("%d", &m)
	while (m--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", rmq(l, r));
	}
	return 0;
}