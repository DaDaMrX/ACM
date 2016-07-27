//dfs+状态压缩
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;
int n, ans;
inline int lowbit(int x) { return x & -x; }
void dfs(int i, int left, int col, int right)
{
	if (i > n)
	{
		ans++;
		return;
	}
	int mask = (1 << n) - 1 & ~(left | col | right);
	while (mask)
	{
		int now = lowbit(mask);
		mask -= now;
		dfs(i + 1, (left | now) << 1, col | now, (right | now) >> 1);
	}
}
int main()
{
	while (scanf("%d", &n), n)
	{
		ans = 0;
		dfs(1, 0, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}

//dfs
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