/*
HDU 5772 String problem (最大权闭合子图)
考虑三种点
1.Pij(1<=i< j<=n)，表示子序列中有第i个字符和第j个字符，这个点的点权是w[i][[j]+w[j][i]
2.i(1<=i<=n)，表示子序列中有i字符x，这个点的点权是-ax
3.x(0<=x<=9)，表示子序列中有x这个数字，这个点的点权是-(bx-ax)
选Pij就要选i点和j点，选i点就要选s[i]这个数字，选j点就要选s[j]这个数字
问题变成从上面三种点中选择若干点使得所选点满足上述关系且总点权最大，问题转化成求最大权闭合子图问题
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 6e3;
const int M = 1e5;

struct Edge
{
	int to, c, next;
	Edge() {};
	Edge(int to, int c, int next) : to(to), c(c), next(next) {};
} edge[2 * M];
int head[N], no;
void init()
{
	memset(head, -1, sizeof(head));
	no = 0;
}
void add(int u, int v, int c)
{
	edge[no] = Edge(v, c, head[u]);
	head[u] = no++;
	edge[no] = Edge(u, 0, head[v]);
	head[v] = no++;
}
queue<int> q;
int level[N];
bool bfs(int s, int t)
{
	while (!q.empty()) q.pop();
	memset(level, -1, sizeof(level));
	level[s] = 0; q.push(s);
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			Edge &e = edge[i];
			if (e.c && level[e.to] < 0)
			{
				level[e.to] = level[u] + 1;
				if (e.to == t) return true;
				q.push(e.to);
			}
		}
	}
	return false;
}
int cur[N];
int dfs(int u, int t, int flow)
{
	if (u == t) return flow;
	for (int &i = cur[u]; i != -1; i = edge[i].next)
	{
		Edge &e = edge[i];
		if (e.c && level[e.to] > level[u])
		{
			int f = dfs(e.to, t, min(flow, e.c));
			if (f)
			{
				e.c -= f;
				edge[i ^ 1].c += f;
				return f;
			}
		}
	}
	return 0;
}
int dinic(int s, int t)
{
	int flow = 0;
	while (bfs(s, t))
	{
		memcpy(cur, head, sizeof(head));
		int f;
		while (f = dfs(s, t, INF)) flow += f;
	}
	return flow;
}

int str[110], a[15], b[15], w[110][110];
int main()
{
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%1d", &str[i]);
		for (int i = 0; i < 10; i++)scanf("%d%d", &a[i], &b[i]);
		int sum = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &w[i][j]);
				sum += w[i][j];
			}

		init();
		int s = 0;
		int ss = n * (n - 1) / 2;
		int t = ss + n + 11;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
			{
				cnt++;
				add(s, cnt, w[i][j] + w[j][i]);
				add(cnt, ss + i, INF);
				add(cnt, ss + j, INF);
			}
		for (int i = 1; i <= n; i++)
		{
			add(ss + i, t, a[str[i]]);
			add(ss + i, ss + n + str[i] + 1, INF);
		}
		for (int i = 0; i < 10; i++)
		{
			add(ss + n + i + 1, t, b[i] - a[i]);
		}

		printf("Case #%d: %d\n", cas, sum - dinic(s, t));
	}
}