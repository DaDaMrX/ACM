/*
HDU 5521 Meeting (最短路+完全图建图)
1.N=1e5，直接开map太大，必须用邻接表
2.sum{Si}=1e6，极端情况，一个完全图包含所有1e5个点，需建1e10条边，TLE
3.因此需考虑利用题目条件简化
4.完全图，图中边权全部相同：对每个完全图，建一个超级源点，
图中所有点到超级源点的边权为0，超级源点到其他点的边权为t
5.1e6个点只需建2e6条边，解决
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 2e6 + 10;

struct Edge
{
	int to, w;
	Edge() {};
	Edge(int to, int w) : to(to), w(w) {};
};
vector<Edge> vec[N];
int n, m;
ll ans[N];

ll dis1[N], dis2[N];
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > pq;
void dijkstra(int start, ll dis[], int n)
{
	for (int i = 1; i <= n; i++) dis[i] = INF;
	dis[start] = 0;
	while (!pq.empty()) pq.pop();
	pq.push(pii(0, start));
	while (!pq.empty())
	{
		pii p = pq.top(); pq.pop();
		int u = p.second;
		if (dis[u] < p.first) continue;
		for (int j = 0; j < vec[u].size(); j++)
		{
			Edge e = vec[u][j];
			int sum = dis[u] + e.w;
			if (sum < dis[e.to])
			{
				dis[e.to] = sum;
				pq.push(pii(dis[e.to], e.to));
			}
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		printf("Case #%d: ", cas);
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n + m; i++) vec[i].clear();
		for (int i = 1; i <= m; i++)
		{
			int w, s;
			scanf("%d%d", &w, &s);
			for (int j = 1; j <= s; j++)
			{
				int u;
				scanf("%d", &u);
				vec[u].push_back(Edge(n + i, 0));
				vec[n + i].push_back(Edge(u, w));
			}
		}

		dijkstra(1, dis1, n + m);
		if (dis1[n] == INF)
		{
			printf("Evil John\n");
			continue;
		}
		dijkstra(n, dis2, n + m);

		ll minx = INF;
		int top = 0;
		for (int i = 1; i <= n; i++)
		{
			ll time = max(dis1[i], dis2[i]);
			if (time == minx) ans[++top] = i;
			else if (time < minx)
			{
				minx = time;
				top = 0;
				ans[++top] = i;
			}
		}
		printf("%I64d\n", minx);
		for (int i = 1; i < top; i++) printf("%d ", ans[i]);
		printf("%d\n", ans[top]);
	}
	return 0;
}