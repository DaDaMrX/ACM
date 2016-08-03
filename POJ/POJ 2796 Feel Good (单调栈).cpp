/*
POJ 2796 Feel Good (单调栈)
从左到右和从右到左跑两遍单调栈，得到以每个元素为最小值向左和向右能够延伸的最大区间
更新结果ans = max{ (sum[right[i]] - sum[left[i] - 1]) * a[i] }
PS：total>=ans更新，total>ans则WA
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e5 + 10;

int n, a[N];
ll sum[N];

int st[N], top;
int right[N];
void monotone_left(int n)
{
	top = 0;
	for (int i = 1; i <= n; i++)
	{
		while (top && a[i] < a[st[top]])
		{
			right[st[top]] = i - 1;
			top--;
		}
		st[++top] = i;
	}
	while (top)
	{
		right[st[top]] = n;
		top--;
	}
}
int left[N];
void monotone_right(int n)
{
	top = 0;
	for (int i = n; i >= 1; i--)
	{
		while (top && a[i] < a[st[top]])
		{
			left[st[top]] = i + 1;
			top--;
		}
		st[++top] = i;
	}
	while (top)
	{
		left[st[top]] = 1;
		top--;
	}
}

int main()
{
	scanf("%d", &n);
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}

	monotone_left(n);
	monotone_right(n);

	ll ans = 0;
	int ans_left, ans_right;
	for (int i = 1; i <= n; i++)
	{
		ll total = (sum[right[i]] - sum[left[i] - 1]) * a[i];
		if (total >= ans)
		{
			ans = total;
			ans_left = left[i];
			ans_right = right[i];
		}
	}

	printf("%lld\n", ans);
	printf("%d %d\n", ans_left, ans_right);
	return 0;
}