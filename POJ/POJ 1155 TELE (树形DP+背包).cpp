#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 3e3 + 10;

struct Edge
{
	int to, w, next;
} e[N * 2];
int head[N], tol;
int n, m;

int num[N], dp[N][N];

void add(int u, int v, int w)
{
	e[tol].to = v;
	e[tol].w = w;
	e[tol].next = head[u];
	head[u] = tol++;
}

void dfs(int u)
{
	for (int i = head[u]; i != -1; i = e[i].next)
	{
		int v = e[i].to;
		dfs(v);
		num[u] += num[v];
		for (int j = num[u]; j > 0; j--)
			for (int k = 1; k <= num[v]; k++)
				dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k] - e[i].w);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	memset(head, -1, sizeof(head));
	tol = 0;
	for (int i = 1; i <= n - m; i++)
	{
		int sum;
		scanf("%d", &sum);
		for (int j = 1; j <= sum; j++)
		{
			int to, w;
			scanf("%d%d", &to, &w);
			add(i, to, w);
		}
		num[i] = 0;
	}
	for (int i = 0; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dp[i][j] = -INF;
	for (int i = n - m + 1; i <= n; i++)
	{
		scanf("%d", &dp[i][1]);
		num[i] = 1;
	}
	dfs(1);
	for (int j = m; j >= 0; j--)
		if (dp[1][j] >= 0)
		{
			printf("%d\n", j);
			break;
		}
	return 0;
}