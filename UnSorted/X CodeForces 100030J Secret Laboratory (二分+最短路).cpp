/********************************************************************************
XProblem J. Secret Laboratory (二分+最短路)
Wrong answer on test 11
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;
const int M = 4e3 + 10;
const int S = 1e6 + 10;

struct Edge
{
	int to, d, s, next;
	Edge() {};
	Edge(int to, int d, int s, int next): to(to), d(d), s(s), next(next) {};
} edge[M];
int adj[N], no;
int n, m;

void init()
{
	memset(adj, -1, sizeof(adj));
	no = 0;
}
void add(int u, int v, int d, int s)
{
	edge[no] = Edge(v, d, s, adj[u]);
	adj[u] = no++;
}

ll dis[N];
typedef pair<ll, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > pq;
ll dijkstra(int start, int level)
{
	memset(dis, 0x7f, sizeof(dis));
	dis[start] = 0;
	while (!pq.empty()) pq.pop();
	pq.push(pii(0, start));
	while (!pq.empty())
	{
		pii p = pq.top(); pq.pop();
		int u = p.second;
		if (dis[u] < p.first) continue;
		for (int i = adj[u]; i != -1; i = edge[i].next)
		{
			Edge &e = edge[i];
			if (e.s > level) continue;
			ll sum = dis[u] + e.d;
			if (sum < dis[e.to])
			{
				dis[e.to] = sum;
				pq.push(pii(dis[e.to], e.to));
			}
		}
	}
	return dis[n];
}

bool cnt[S];
int secret[M], num;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	init();
	memset(cnt, false, sizeof(cnt));
	for (int i = 1; i <= m; i++)
	{
		int u, v, d, s;
		scanf("%d%d%d%d", &u, &v, &d, &s);
		add(u, v, d, s);
		add(v, u, d, s);
		cnt[s] = true;
	}
	ll T;
	scanf("%I64d", &T);

	secret[0] = 0;
	num = 1;
	for (int i = 1; i < S; i++)
		if (cnt[i]) secret[num++] = i;
	
	int left = 0, right = num;
	ll time;
	while (right - left > 1)
	{
		int mid = left + right >> 1;
		if ((time = dijkstra(1, secret[mid])) <= T) right = mid;
		else left = mid;
	}

	if (right == num) printf("NO\n");
	else printf("YES\n%d %I64d\n", secret[right], time);
	return 0;
}
