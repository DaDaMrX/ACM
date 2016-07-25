#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 5e4 + 10;

struct Edge
{
	int to, next;
} e[N * 2];
int head[N], num;

int n;
int cnt[N], f[N];
bool vis[N];
vector<int> res;

void add(int u, int v)
{
	e[num].to = v;
	e[num].next = head[u];
	head[u] = num++;
}

void dfs(int i)
{
	vis[i] = true;
	cnt[i] = 1;
	for (int j = head[i]; j != -1; j = e[j].next)
		if (!vis[e[j].to])
		{
			dfs(e[j].to);
			cnt[i] += cnt[e[j].to];
		}
}
int main()
{
	scanf("%d", &n);
	memset(head, -1, sizeof(head));
	num = 0;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
		add(b, a);
	}

	memset(vis, false, sizeof(vis));
	dfs(1);

	for (int i = 1; i <= n; i++)
	{
		f[i] = n - cnt[i];
		if (f[i] > cnt[i]) continue;
		for (int j = head[i]; j != -1; j = e[j].next)
			if (cnt[e[j].to] < cnt[i] && cnt[e[j].to] > f[i])
				f[i] = cnt[e[j].to];
	}

	int minx = INF;
	for (int i = 1; i <= n; i++)
	{
		if (f[i] < minx)
		{
			minx = f[i];
			res.clear();
			res.push_back(i);
		}
		else if (f[i] == minx)
		{
			res.push_back(i);
		}
	}

	printf("%d", res[0]);
	for (int i = 1; i < res.size(); i++) printf(" %d", res[i]);
	printf("\n");
	return 0;
}