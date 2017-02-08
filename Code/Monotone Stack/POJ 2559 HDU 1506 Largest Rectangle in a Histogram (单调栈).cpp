/*
HDU 1506 Largest Rectangle in a Histogram (单调栈)
左右各做一次单调栈，求出每个柱形的左右延拓，取最大值即可
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e5 + 10;

int n, a[N], left[N], right[N];
int st[N], top;

int main()
{
	while (scanf("%d", &n), n)
	{
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

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

		ll ans = 0;
		for (int i = 1; i <= n; i++)
			ans = max(ans, (ll)(right[i] - left[i] + 1) * a[i]);
		printf("%I64d\n", ans);
	}
	return 0;
}