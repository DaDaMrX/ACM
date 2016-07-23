/*
Bellman-Ford algorithm
有向图，可以有负边， 可以判负环
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e3 + 10;
const int M = 1e4 + 10;
struct Graph
{
	int n, m;
	struct Edge
	{
		int from, to, w;
		Edge() {};
		Edge(int from, int to, int w) : from(from), to(to), w(w) {};
	} e[M];
	void setEdge(int n, int m);
	int dis[N];
	void bellman(int start);
};
void Graph::setEdge(int n, int m)
{
	this->n = n; this->m = m;
	for (int i = 1; i <= m; i++)
	{
		int from, to, w;
		scanf("%d%d%d", &from, &to, &w);
		e[i] = Edge(from, to, w);
	}
}
void Graph::bellman(int start)
{
	memset(dis, 0x7f, sizeof(dis));
	this->dis[start] = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (dis[e[j].from] < 0x7f7f7f7f)
				dis[e[j].to] = min(dis[e[j].to], dis[e[j].from] + e[j].w);
		}
	}
}
Graph G;
int main()
{
	int n, m;
	while (~scanf("%d%d", &n, &m))
	{
		G.setEdge(n, m);
		G.bellman(1);
		for (int i = 1; i <= n; i++)
			printf("%d: %d\n", i, G.dis[i]);
	}
	return 0;
}
/*
Sample Input:
6 10
1 2 50
1 3 30
1 4 100
1 5 10
2 6 10
3 2 5
3 6 20
4 2 20
4 3 50
5 4 10

Sample Output:
1: 0
2: 35
3: 30
4: 20
5: 10
6: 45
*/