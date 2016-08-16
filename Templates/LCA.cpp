//RMQ O(nlogn)预处理 O(1)查询 ***
int dis[N], first[N];
int pos[2 * N], deep[2 * N], dfsOrder;
void dfs(int u, int father, int w)
{
    dfsOrder++;
    pos[dfsOrder] = u; first[u] = dfsOrder; deep[dfsOrder] = deep[father] + 1;
    dis[u] = dis[father] + w;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        Edge &e = edge[i];
        if (e.to != father)
        {
            dfs(e.to, u, e.w);
            dfsOrder++;
            pos[dfsOrder] = u;
            deep[dfsOrder] = deep[father] + 1;
        }
    }
}
int dp[2 * N][20], lg[2 * N];
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
			dp[i][j] = deep[x] < deep[y] ? x : y;
		}
}
int rmq(int left, int right)
{
	int k = lg[right - left + 1];
	int x = dp[left][k], y = dp[right - (1 << k) + 1][k];
	return deep[x] < deep[y] ? x : y;
}
int lca(int u, int v)
{
    int x = first[u], y = first[v];
    if (x > y) swap(x, y);
    return pos[rmq(x, y)];
}

//在线倍增法 O(nlogn)预处理 O(logn)查询
int p[N][20];
int deep[N], dis[N], fa[N];
void dfs(int u, int father, int w)
{
	fa[u] = father;
	deep[u] = deep[father] + 1;
	dis[u] = dis[father] + w;
	p[u][0] = father;
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		Edge &e = edge[i];
		if (e.to != father) dfs(e.to, u, e.w);
	}
}
void init(int n)
{
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i <= n; i++)
			if (p[i][j - 1] != -1)
				p[i][j] = p[p[i][j - 1]][j - 1];
}
int lca(int u, int v)
{
	if (deep[u] < deep[v]) swap(u, v);
	int i = 0;
	while ((1 << i) <= deep[u]) i++;
	i--;
	for (int j = i; j >= 0; j--)
		if (deep[u] - (1 << j) >= deep[v])
			u = p[u][j];
	if (u == v) return u;
	for (int j = i; j >= 0; j--)
		if (p[u][j] != -1 && p[u][j] != p[v][j])
		{
			u = p[u][j];
			v = p[v][j];
		}
	return p[u][0];
}

//暴力
int deep[N], dis[N], fa[N];
void dfs(int u, int father, int w)
{
	fa[u] = father;
	deep[u] = deep[father] + 1;
	dis[u] = dis[father] + w;
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		Edge &e = edge[i];
		if (e.to != father) dfs(e.to, u, e.w);
	}
}
int lca(int u, int v)
{
	if (deep[u] < deep[v]) swap(u, v);
	while (deep[u] > deep[v]) u = fa[u];
	while (u != v) u = fa[u], v = fa[v];
	return u;
}