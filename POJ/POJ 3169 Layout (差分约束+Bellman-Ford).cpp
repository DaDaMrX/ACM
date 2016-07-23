#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;
const int M = 3e4 + 10;
struct Graph
{
	int n, m;
	struct Edge
	{
		int from, to, w;
		Edge() {};
		Edge(int from, int to, int w) : from(from), to(to), w(w) {};
	} e[M];
	void setEdge(int n, int ml, int md);
	int dis[N];
	void bellman(int start);
};
void Graph::setEdge(int n, int ml, int md)
{
	this->n = n; this->m = n - 1 + ml + md;
	int cnt = 0;
	for (int i = 1; i < n; i++)
	{
		e[cnt++] = Edge(i + 1, i, 0);
	}
	for (int i = 1; i <= ml; i++)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		e[cnt++] = Edge(a, b, w);
	}
	for (int i = 1; i <= md; i++)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		e[cnt++] = Edge(b, a, -w);
	}
}
void Graph::bellman(int start)
{
	memset(this->dis, 0x7f, sizeof(this->dis));
	this->dis[start] = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			Edge e = this->e[j];
			if (dis[e.from] < INF && dis[e.from] + e.w < dis[e.to])
			{
				dis[e.to] = dis[e.from] + e.w;
			}
		}
	}
}
Graph G;
int main()
{
	int n, ml, md;
	while (~scanf("%d%d%d", &n, &ml, &md))
	{
		G.setEdge(n, ml, md);
		G.bellman(1);
		if (G.dis[1] < 0) printf("-1\n");
		else if (G.dis[n] == INF) printf("-2\n");
		else printf("%d\n", G.dis[n]);
	}
	return 0;
}