#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 5e3 + 10;

struct Edge
{
	int to, w;
	Edge() {};
	Edge(int to, int w) : to(to), w(w) {};
};
vector<Edge> vec[N];
int n, m;

int dis1[N], dis2[N];
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > pq;
void dijkstra(int start)
{
	memset(dis1, 0x7f, sizeof(dis1));
	memset(dis2, 0x7f, sizeof(dis2));
	dis1[start] = 0;
	while (!pq.empty()) pq.pop();
	pq.push(pii(0, start));
	while (!pq.empty())
	{
		pii p = pq.top(); pq.pop();
		int u = p.second, d = p.first;
		if (dis2[u] < d) continue;
		for (int j = 0; j < vec[u].size(); j++)
		{
			Edge e = vec[u][j];
			int sum = d + e.w;
			if (sum < dis1[e.to])
			{
				dis2[e.to] = dis1[e.to];
				dis1[e.to] = sum;
				pq.push(pii(dis1[e.to], e.to));
				pq.push(pii(dis2[e.to], e.to));
			}
			else if (sum > dis1[e.to] && sum < dis2[e.to])
			{
				dis2[e.to] = sum;
				pq.push(pii(dis2[e.to], e.to));
			}
		}
	}
}

int main()
{
	while (~scanf("%d%d", &n, &m))
	{
		for (int i = 1; i <= n; i++) vec[i].clear();
		for (int i = 1; i <= m; i++)
		{
			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			vec[a].push_back(Edge(b, w));
			vec[b].push_back(Edge(a, w));
		}

		dijkstra(1);

		printf("%d\n", dis2[n]);
	}
	return 0;
}