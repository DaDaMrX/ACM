/*
HDU 2063 过山车 (二分图匹配)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 510;

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
int hungary()
{
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
	int k;
	while (scanf("%d", &k), k)
	{
		scanf("%d%d", &left, &right);
		memset(g, 0, sizeof(g));
		while (k--)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			g[a][b] = 1;
		}
		printf("%d\n", hungary());
	}
}