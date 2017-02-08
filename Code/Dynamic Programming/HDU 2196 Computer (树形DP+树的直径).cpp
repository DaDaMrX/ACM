#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e4 + 10;

struct Edge
{
	int to, w;
	Edge() {};
	Edge(int to, int w) : to(to), w(w) {};
};
vector<Edge> vec[N];

int n, m;
int dis1[N], dis2[N];
bool vis[N];

void dfs(int from, int dis[])
{
	for (auto e : vec[from])
		if (!vis[e.to])
		{
			dis[e.to] = dis[from] + e.w;
			vis[e.to] = true;
			dfs(e.to, dis);
		}
}

int findmax(int dis[])
{
	int u = -1;
	for (int i = 1; i <= n; i++)
		if (u == -1 || dis[i] > dis[u]) u = i;
	return u;
}

int main()
{
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i++) vec[i].clear();
		for (int i = 2; i <= n; i++)
		{
			int b, w;
			scanf("%d%d", &b, &w);
			vec[i].push_back(Edge(b, w));
			vec[b].push_back(Edge(i, w));
		}

		memset(dis1, 0, sizeof(dis1));
		memset(vis, false, sizeof(vis));
		vis[1] = true;
		dfs(1, dis1);
		int s = findmax(dis1);

		memset(dis1, 0, sizeof(dis1));
		memset(vis, false, sizeof(vis));
		vis[s] = true;
		dfs(s, dis1);
		int t = findmax(dis1);

		memset(dis2, 0, sizeof(dis2));
		memset(vis, false, sizeof(vis));
		vis[t] = true;
		dfs(t, dis2);

		for (int i = 1; i <= n; i++)
			printf("%d\n", max(dis1[i], dis2[i]));
	}
	return 0;
}