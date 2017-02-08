/*
HDU 1151 Air Raid (最小路径覆盖)
把每个点都拆为两个，一个在左边集合，一个在右边集合，有边就在左右集合间连边
DAG上的最小路径覆盖=顶点数-最大匹配数
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 150;

int left, right;
bool g[N][N];
int match[N];
bool vis[N];
bool dfs(int u)
{
	for (int v = 1; v <= right; v++)
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
int hungary(int l, int r)
{
	left = l; right = r;
	int ans = 0;
	memset(match, -1, sizeof(match));
	for (int u = 1; u <= left; u++)
	{
		memset(vis, false, sizeof(vis));
		if (dfs(u)) ans++;
	}
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		memset(g, false, sizeof(g));
		while (m--)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			g[a][b] = true;
		}
		printf("%d\n", n - hungary(n, n));
	}
	return 0;
}