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
int hungary(int x, int y)
{
	left = x; right = y;
	int ans = 0;
	memset(match, -1, sizeof(match));
	for (int u = 1; u <= left; u++)
	{
		memset(vis, false, sizeof(vis));
		if (dfs(u)) ans++;
	}
	return ans;
}