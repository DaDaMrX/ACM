//CodeForces Gym 101149I It’s the Police
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10;
const int M = 4e5 + 10;

struct Edge
{
	int to, next;
	Edge() {};
	Edge(int to, int next): to(to), next(next) {};
} edge[M];
int adj[N], no;

void init()
{
	memset(adj, -1, sizeof(adj));
	no = 0;
}
void add(int u, int v)
{
	edge[no] = Edge(v, adj[u]);
	adj[u] = no++;
}

int n, m, deg[N];
bool flag[N];

int main()
{
	scanf("%d%d", &n, &m);
	init();
	memset(deg, 0, sizeof(deg));
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
		deg[u]++;
		deg[v]++;
	}

	deg[0] = INF;
	int t = 0;
	for (int i = 1; i <= n; i++)
		if (deg[i] < deg[t]) t = i;

	memset(flag, true, sizeof(flag));
	flag[t] = false;
	for (int i = adj[t]; i != -1; i = edge[i].next) flag[edge[i].to] = false;

	for (int i = 1; i <= n; i++) printf("%d ", flag[i] ? 1 : 0);
	return 0;
}
