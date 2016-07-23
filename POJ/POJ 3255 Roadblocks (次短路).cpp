#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
const int N = 5e3 + 10;
typedef pair<int, int> pii;
struct Edge
{
	int to, w;
	Edge() {};
	Edge(int to, int w) : to(to), w(w) {};
};
vector<Edge> vec[N];
int dis1[N], dis2[N];
priority_queue<pii, vector<pii>, greater<pii> > q;
int n, m;
void dijkstra(int start)
{
	memset(dis1, 0x7f, sizeof(dis1));
	memset(dis2, 0x7f, sizeof(dis2));
	dis1[start] = 0;
	q.push(pii(dis1[start], start));
	while (!q.empty())
	{
		pii p = q.top(); q.pop();
		int u = p.second, d = p.first;
		for (int i = 0; i < vec[u].size(); i++)
		{
			Edge e = vec[u][i];
			if (d + e.w < dis1[e.to])
			{
				dis2[e.to] = dis1[e.to];
				dis1[e.to] = d + e.w;
				q.push(pii(dis2[e.to], e.to));
				q.push(pii(dis1[e.to], e.to));
			}
			else if (dis1[e.to] < d + e.w && d + e.w < dis2[e.to])
			{
				dis2[e.to] = d + e.w;
				q.push(pii(dis2[e.to], e.to));
			}
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) vec[i].clear();
	for (int i = 1; i <= m; i++)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		vec[a].push_back(Edge(b, w));
		vec[b].push_back(Edge(a, w));
	}
	dijkstra(1);
	printf("%d\n", dis2[n]);
	return 0;
}