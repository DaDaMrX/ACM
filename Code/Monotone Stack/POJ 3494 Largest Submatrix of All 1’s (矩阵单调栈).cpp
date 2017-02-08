/*
POJ 3494 Largest Submatrix of All 1’s (矩阵单调栈)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 2e3 + 10;

int m, n, a[N][N];

int st[N], top;
int right[N];
void monotone_left(int i, int n)
{
	top = 0;
	for (int j = 1; j <= n; j++)
	{
		while (top && a[i][j] < a[i][st[top]])
		{
			right[st[top]] = j - 1;
			top--;
		}
		st[++top] = j;
	}
	while (top)
	{
		right[st[top]] = n;
		top--;
	}
}
int left[N];
void monotone_right(int i, int n)
{
	top = 0;
	for (int j = n; j >= 1; j--)
	{
		while (top && a[i][j] < a[i][st[top]])
		{
			left[st[top]] = j + 1;
			top--;
		}
		st[++top] = j;
	}
	while (top)
	{
		left[st[top]] = 1;
		top--;
	}
}

int main()
{
	while (~scanf("%d%d", &m, &n))
	{
		memset(a[0], 0, sizeof(a[0]));
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				int t;
				scanf("%d", &t);
				a[i][j] = t ? a[i - 1][j] + t : 0;
			}

		int ans = 0;
		for (int i = 1; i <= m; i++)
		{
			monotone_left(i, n);
			monotone_right(i, n);
			for (int j = 1; j <= n; j++)
			{
				int total = a[i][j] * (right[j] - left[j] + 1);
				ans = max(ans, total);
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}