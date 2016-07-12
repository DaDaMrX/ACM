#include <cstdio>
#include <cstring>
#define N 15
int n, count;
int ans[N];
bool column[N], left[2 * N + 5], right[2 * N + 5];
void dfs(int i)
{
	if (i > n)
	{
		count++;
		return;
	}
	for (int j = 1; j <= n; j++)
		if (column[j] && left[i + j] && right[i - j + N])
		{
			column[j] = false; left[i + j] = false; right[i - j + N] = false;
			dfs(i + 1);
			column[j] = true; left[i + j] = true; right[i - j + N] = true;
		}
}
int main()
{
	memset(ans, -1, sizeof(ans));
	while (scanf("%d", &n), n)
	{
		if (~ans[n])
		{
			printf("%d\n", ans[n]);
			continue;
		}
		count = 0;
		memset(column, true, sizeof(column));
		memset(left, true, sizeof(left));
		memset(right, true, sizeof(right));
		dfs(1);
		ans[n] = count;
		printf("%d\n", ans[n]);
	}
	return 0;
}