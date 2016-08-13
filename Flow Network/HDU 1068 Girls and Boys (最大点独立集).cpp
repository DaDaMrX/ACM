/*
HDU 1068 Girls and Boys (最大点独立集)
由于题目输入没有区分男女，我们让左右集合都有n个人，相当于合并了两个二分图，
左边的男生根右边的女生匹配，左边的女生跟右边的男生匹配。
最后结果ans=n-hangary()/2
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int left, right;
bool g[N][N];
int match[N];
bool vis[N];
bool dfs(int u)
{
	for (int v = 0; v < right; v++)
		if (g[u][v] && !vis[v])
		{
			vis[v] = true;
			if (match[v] < 0 || dfs(match[v]))
			{
				match[v] = u;
				return true;
			}
		}
	return false;
}
int hungary()
{
	int ans = 0;
	memset(match, -1, sizeof(match));
	for (int u = 0; u < left; u++)
	{
		memset(vis, false, sizeof(vis));
		if (dfs(u)) ans++;
	}
	return ans;
}

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		left = right = n;
		memset(g, false, sizeof(g));
		for (int i = 0; i < n; i++)
		{
			int sum;
			scanf("%*d: (%d)", &sum);
			while (sum--)
			{
				int j;
				scanf("%d", &j);
				g[i][j] = true;
			}
		}
		printf("%d\n", n - hungary() / 2);
	}
	return 0;
}