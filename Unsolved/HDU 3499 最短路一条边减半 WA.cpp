#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <functional>
using namespace std;
const int N = 1e5 + 10;
const int INF = 0x7f7f7f7f;
typedef pair<int, int> pii;
struct Edge
{
	int to, w;
	Edge() {};
	Edge(int to, int w) : to(to), w(w) {};
};
map<string, int> mp;
vector<Edge> vec1[N], vec2[N];
int dis1[N], dis2[N];
priority_queue<pii, vector<pii>, greater<pii> > pq;
int n, m, start, finish;
void dijkstra(int start, vector<Edge> vec[], int dis[])
{
	for (int i = 1; i <= n; i++) dis[i] = INF;
	dis[start] = 0;
	while (!pq.empty()) pq.pop();
	pq.push(pii(dis[start], start));
	while (!pq.empty())
	{
		pii p = pq.top(); pq.pop();
		int u = p.second;
		for (int i = 0; i < vec[u].size(); i++)
		{
			Edge e = vec[u][i];
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
	while (~scanf("%d%d", &n, &m))
	{
		for (int i = 1; i <= n; i++) vec1[i].clear(), vec2[i].clear();
		int cnt = 1;
		for (int i = 1; i <= m; i++)
		{
			string s1, s2;
			int w;
			cin >> s1 >> s2 >> w;
			int a;
			if (mp[s1]) a = mp[s1];
			else a = mp[s1] = cnt++;
			int b;
			if (mp[s2]) b = mp[s2];
			else b = mp[s2] = cnt++;
			vec1[a].push_back(Edge(b, w));
			vec2[b].push_back(Edge(a, w));
		}
		string s1, s2;
		cin >> s1 >> s2;
		start = mp[s1]; finish = mp[s2];
		dijkstra(start, vec1, dis1);
		dijkstra(finish, vec2, dis2);
		int ans = INF;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < vec1[i].size(); j++)
			{
				if (dis1[i] == INF || dis2[vec1[i][j].to] == INF) continue;
				int sum = dis1[i] + vec1[i][j].w / 2 + dis2[vec1[i][j].to];
				if (sum < ans) ans = sum;
			}
		}
		if (ans < INF) printf("%d\n", ans);
		else printf("-1\n");
	}
	return 0;
}