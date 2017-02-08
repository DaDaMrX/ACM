/*
POJ 2516 Minimum Cost (最小费用最大流)
1.本题难点在于，费用与商品，供货商和商店三个因素有关
2.结合题目输入，对每种商品建一次图，计算最小费用最大流，最后累加
3.对于每一种商品，源点与m个供货商之间建立容量为此供货商存货量，花费为0的边，实现对供货商存货的限制
4.m个供货商与n个商店之间建立容量为INF，花费为当前矩阵中对应值的边
5.n个商店与汇点之间建立容量为此商店需求量，花费为0的边，实现对商店的容量限制
6.若对于某一种商品，若总供应量小于总需求量，则说明不能满足所有商店需要，标记，但记得仍需继续读入后续输入
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int maxn = 80;
const int N = 2 * maxn;
const int M = maxn * maxn + maxn;

int head[N], d[N], s, t, no, dis[N][N], vis[N], pre[N];
struct Node
{
	int u, v, flow, next, cost;
	Node() {};
	Node(int x, int y, int z, int w, int c) : u(x), v(y), next(z), flow(w), cost(c) {};
} p[M];
void add(int x, int y, int z, int c)
{
	p[no] = Node(x, y, head[x], z, c); head[x] = no++;
	p[no] = Node(y, x, head[y], 0, -c); head[y] = no++;
}
void init()
{
	memset(head, -1, sizeof(head));
	no = 0;
}
queue<int>q;
bool spfa()
{
	int i, x, y;
	while (!q.empty()) q.pop();
	memset(d, 0x3f, sizeof(d));
	memset(vis, false, sizeof(vis));
	memset(pre, -1, sizeof(pre));
	d[s] = 0; vis[s] = true; q.push(s);
	while (!q.empty())
	{
		x = q.front(); q.pop(); vis[x] = false;
		for (i = head[x]; i != -1; i = p[i].next)
		{
			if (p[i].flow && d[y = p[i].v] > d[x] + p[i].cost)
			{
				d[y] = d[x] + p[i].cost; pre[y] = i;
				if (vis[y])  continue;
				vis[y] = true;  q.push(y);
			}
		}
	}
	return d[t] != d[t + 1];
}
int mcmf()
{
	int mincost = 0, maxflow = 0, minflow, i;
	while (spfa())
	{
		minflow = INF;
		for (i = pre[t]; i != -1; i = pre[p[i].u])
			minflow = min(minflow, p[i].flow);
		for (i = pre[t]; i != -1; i = pre[p[i].u])
		{
			p[i].flow -= minflow;
			p[i ^ 1].flow += minflow;
		}
		mincost += d[t] * minflow; maxflow += minflow;
	}
	return mincost;
}

int n, m, k;
int need[maxn][maxn], supply[maxn][maxn], price[maxn][maxn];

int main()
{
	while (scanf("%d%d%d", &n, &m, &k), n)
	{
		for (int i = 1; i <= n; i++)
			for (int l = 1; l <= k; l++)
				scanf("%d", &need[i][l]);
		for (int j = 1; j <= m; j++)
			for (int l = 1; l <= k; l++)
				scanf("%d", &supply[j][l]);

		bool flag = true;
		int ans = 0;
		for (int l = 1; l <= k; l++)
		{
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++)
					scanf("%d", &price[i][j]);
			if (!flag) continue;

			int total_supply = 0;
			for (int j = 1; j <= m; j++) total_supply += supply[j][l];
			int total_need = 0;
			for (int i = 1; i <= n; i++) total_need += need[i][l];
			if (total_supply < total_need)
			{
				flag = false;
				continue;
			}

			init();
			s = 0; t = m + n + 1;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++)
					add(j, m + i, INF, price[i][j]);
			for (int j = 1; j <= m; j++) add(s, j, supply[j][l], 0);
			for (int i = 1; i <= n; i++) add(m + i, t, need[i][l], 0);
			ans += mcmf();
		}

		if (flag) printf("%d\n", ans);
		else printf("-1\n");
	}
	return 0;
}