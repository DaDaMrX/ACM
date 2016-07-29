//WA
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
typedef pair<long long, int> pii;
struct Edge
{
	int to, w;
	Edge() {};
	Edge(int to, int w) : to(to), w(w) {};
};
map<string, int> mp;
vector<Edge> vec1[N], vec2[N];
long long dis1[N], dis2[N];
priority_queue<pii, vector<pii>, greater<pii> > pq;
int n, m, start, finish;
void dijkstra(int start, vector<Edge> vec[], long long dis[])
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
		if (!(mp[s1] && mp[s2]))
		{
			printf("-1\n");
			continue;
		}
		start = mp[s1]; finish = mp[s2];



		dijkstra(start, vec1, dis1);
		dijkstra(finish, vec2, dis2);
		long long ans = INF * 10000;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < vec1[i].size(); j++)
			{
				if (dis1[i] == INF || dis2[vec1[i][j].to] == INF) continue;
				int sum = dis1[i] + vec1[i][j].w / 2 + dis2[vec1[i][j].to];
				if (sum < ans) ans = sum;
			}
		}
		if (ans < INF) printf("%lld\n", ans);
		else printf("-1\n");
	}
	return 0;
}

//T
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <functional>
#include <map>
#include <string>
using namespace std;
typedef long long ll;
const int INF = 4611686018427387903;
const int N = 1e5 + 10;

struct Edge
{
	int to, w, next;
} e1[N * 2], e2[N * 2];
int head1[N], head2[N], tol1, tol2;
int n, m;

void add1(int u, int v, int w)
{
	e1[tol1].to = v;
	e1[tol1].w = w;
	e1[tol1].next = head1[u];
	head1[u] = tol1++;
}

void add2(int u, int v, int w)
{
	e2[tol2].to = v;
	e2[tol2].w = w;
	e2[tol2].next = head2[u];
	head2[u] = tol2++;
}

map<string, int> mp;

ll dis1[N], dis2[N];
typedef pair<ll, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > pq;
void dijkstra(int start, ll dis[], int head[], Edge e[])
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
		for (int i = head[u]; i != -1; i = e[i].next)
		{
			int sum = dis[u] + e[i].w;
			if (sum < dis[e[i].to])
			{
				dis[e[i].to] = sum;
				pq.push(pii(dis[e[i].to], e[i].to));
			}
		}
	}
}

int main()
{
	while (~scanf("%d%d", &n, &m))
	{
		memset(head1, -1, sizeof(head1));
		tol1 = 0;
		memset(head2, -1, sizeof(head2));
		tol2 = 0;
		mp.clear();
		int num = 1;
		for (int i = 1; i <= m; i++)
		{
			char s1[13], s2[13];
			int a, b, w;
			scanf("%s%s%d", s1, s2, &w);
			string str1(s1), str2(s2);
			if (!mp[str1]) mp[str1] = num++;
			a = mp[str1];
			if (!mp[str2]) mp[str2] = num++;
			b = mp[str2];
			add1(a, b, w);
			add2(b, a, w);
		}
		char s1[13], s2[13];
		scanf("%s%s", s1, s2);
		string str1(s1), str2(s2);
		if (!(mp[str1] && mp[str2]))
		{
			printf("-1\n");
			continue;
		}
		int start = mp[str1], finish = mp[str2];

		dijkstra(start, dis1, head1, e1);
		dijkstra(finish, dis2, head2, e2);

		if (dis1[finish] == INF)
		{
			printf("-1\n");
			continue;
		}
		ll ans = INF;
		for (int i = 1; i <= n; i++)
			for (int j = head1[i]; j != -1; j = e1[j].next)
			{
				ans = min(ans, dis1[i] + e1[j].w / 2 + dis2[e1[j].to]);
			}
		if (ans < INF) printf("%lld\n", ans);
		else printf("-1\n");
	}
	return 0;
}